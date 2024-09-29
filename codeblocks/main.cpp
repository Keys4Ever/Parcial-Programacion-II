#include <iostream>
#include <cstring>
using namespace std;
#include "modeloparcial.h"
void menu();
void handleOption(int);

/**
Generar un archivo con las compras realizadas este año. Cada registro debe tener el número de compra, el número de proveedor y el importe
*/

class CompraRealizada{
public:
	void setNCompra(int n){nCompra = n;}
	void setNProveedor(int n){nProveedor = n;}
	void setImporte(float n){imp = n;}

	int getNCompra(){ return nCompra; }
	int getNProveedor(){ return nProveedor; }
	float getImporte(){ return imp; }
private:
	int nCompra;
	int nProveedor;
	float imp;
};

class ArchivoComprasRealizadas{
private:
    int nroCompra;
    int nroProveedor;
    float importe;
	char nombre[30];
public:

	  void mostrarTodos() {
        FILE* p = fopen(nombre, "rb");
        if (p == nullptr) {
            std::cout << "Error al abrir el archivo: " << nombre << std::endl;
            return;
        }

        Compra compra;
        int registrosLeidos = 0;

        while (fread(&compra, sizeof(Compra), 1, p) == 1) {
            compra.Mostrar();
            registrosLeidos++;
        }

        if (registrosLeidos == 0) {
            std::cout << "No se encontraron registros en el archivo." << std::endl;
        }

        fclose(p);
    }

	bool grabarRegistro(CompraRealizada reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
	ArchivoComprasRealizadas(const char *p="comprasRealizadasAnuales.dat"){
		strcpy(nombre, p);
	}
	char* getNombre(){ return nombre; }

    void setNroCompra(int nro) { nroCompra = nro; }
    int getNroCompra(){ return nroCompra; }

    void setNroProveedor(int nro) { nroProveedor = nro; }
    int getNroProveedor(){ return nroProveedor; }

    void setImporte(float imp) { importe = imp; }
    float getImporte(){ return importe; }
};

void generarArchivoCompras(int anio=2024){
	ArchivoComprasRealizadas obj("comprasRealizadasAnuales.dat");
	FILE *p = fopen(obj.getNombre(), "ab");
	if (p == NULL) return;

	ArchivoCompras compras("compras.dat");
	int cantCompras = compras.contarRegistros();

	for (int i=0;i<cantCompras;i++){
		Compra compra = compras.leerRegistro(i);
		if (compra.getActivo()){
			if(compra.getFechaCompra().getAnio() == anio){
				CompraRealizada comp;
				comp.setImporte(compra.getImporte());
				comp.setNCompra(compra.getNumeroCompra());
				comp.setNProveedor(compra.getNumeroproveedor());

				obj.grabarRegistro(comp);
			}
		}
	}
	fclose(p);
}

bool hasSellsThisYear(Proveedor prove, int anio = 2024){
	ArchivoCompras arch("compras.dat");
	int cantRegistros = arch.contarRegistros();
	for (int i = 0; i < cantRegistros ; i++){
		Compra compra;
		compra = arch.leerRegistro(i);
		if (compra.getActivo()){
			if (compra.getNumeroproveedor() == prove.getNumeroProveedor()){
				if(compra.getFechaCompra().getAnio() == anio){
					return true;
				}
			}
		}
	}
	return false;

}

int provinciaConMasProveedoresConCompras() {
    ArchivoProveedores arch("proveedores.dat");
    int cantRegistros = arch.contarRegistros();

    int contador[25] = {0}; // Suponiendo 24 provincias (1 a 24)

    // Contar provincias registradas
    for (int i = 0; i < cantRegistros; i++) {
        Proveedor obj = arch.leerRegistro(i);
		if (obj.getActivo()){
			if (hasSellsThisYear(obj)){
				contador[obj.getProvincia()]++;
			}
		}
    }

    // Encontrar la provincia con más proveedores
    int provinciaConMasProveedores = 0;
    int maxProveedores = 0;

    for (int i = 1; i <= 24; i++) {
        if (contador[i] > maxProveedores) {
            maxProveedores = contador[i];
            provinciaConMasProveedores = i;
        }
    }

    return provinciaConMasProveedores;
}

int provinciaConMasProveedores() {
    ArchivoProveedores arch("proveedores.dat");
    int cantRegistros = arch.contarRegistros();

    int contador[25] = {0}; // Suponiendo 24 provincias (1 a 24)

    // Contar provincias registradas
    for (int i = 0; i < cantRegistros; i++) {
        Proveedor obj = arch.leerRegistro(i);
		if (obj.getActivo()){
			contador[obj.getProvincia()]++;

		}
    }

    // Encontrar la provincia con más proveedores
    int provinciaConMasProveedores = 0;
    int maxProveedores = 0;

    for (int i = 1; i <= 24; i++) {
        if (contador[i] > maxProveedores) {
            maxProveedores = contador[i];
            provinciaConMasProveedores = i;
        }
    }

    return provinciaConMasProveedores;
}
void MostrarCiertosMateriales(int tipo){
	ArchivoMateriales arch("materiales.dat");
	int cantRegistros = arch.contarRegistros();

	for (int i = 0; i < cantRegistros; i++){
			Material obj = arch.leerRegistro(i);
			if (obj.getActivo()){
				if (obj.getTipo() == tipo){
					obj.Mostrar();
					cout << "---------------------"<<endl;
				}
			}
	}
}

void handleOption(int option){
	int tipo;
	switch (option)
	{
	case 1:
		generarArchivoCompras();
		break;
	case 2:
		cout << "Provincia con mas proveedores: " << provinciaConMasProveedores() << endl;

		break;
	case 3:
		cout << "Provincia con mas proveedores con compras: " << provinciaConMasProveedoresConCompras() << endl;
		break;
	case 4:
		cout << "Ingrese el tipo a buscar: ";
		cin >> tipo;
		MostrarCiertosMateriales(tipo);
		break;
	default:
		return;
		break;
	}
	menu();

}

void menu(){
	int opcion = 0;
	cout << "================================"  << endl;
	cout << "=======1. Compras anuales======="  << endl;
	cout << "==2. Provincia Mas proveedores=="  << endl;
	cout << "==3. Provincia Mas proveedores c. Ventas=="  << endl;
	cout << "======4. Buscar materiales======"  << endl;
	cout << "================================"  << endl;
	cout << "Opcion deseada: ";
	cin >> opcion;
	system("pause");
	system("cls");

	handleOption(opcion);
}

int main(){

	menu();
    return 0;
}
