# Carrera: Técnico Universitario en Programación
## Materia: Programación II
### Tema: Datos y consignas para resolver el parcial 1

## Índice
1. [Modelo Parcial - Programación II](#modelo-parcial---programación-ii)
2. [Enunciado parcial](#enunciado-parcial)
   - [obras.dat](#obrasdat)
   - [materiales.dat](#materialesdat)
   - [compras.dat](#comprasdat)
   - [proveedores.dat](#proveedoresdat)
3. [Preguntas](#preguntas)
4. [Desafío](#desafío)
   - [Punto 2 modificado](#punto-2-modificado)

---

## Modelo Parcial - Programación II

Resolver las preguntas que se encuentran al final del enunciado en un archivo `cpp` de nombre `apellido_nombre.cpp`. Por cada pregunta se debe desarrollar una función global que la resuelva. Las funciones con la resolución deben ser llamadas en `main()` (preferentemente se espera que se desarrolle un menú que llame a cada función).

**NOTA:** El archivo `modeloparcial.h` se debe incluir como archivo externo. **NO COPIARLO EN EL CPP QUE SE ENTREGA. TAMPOCO SE DEBE ENTREGAR Y FUNDAMENTAL, NO SE PUEDE MODIFICAR EL `.H`.**

Todo el código, incluidas las clases nuevas (si fuera necesario hacerlas), tiene que estar en el archivo `cpp`.

---

## Enunciado parcial

Una empresa constructora tiene, entre otros, los siguientes archivos en su sistema de información:

### `obras.dat`
- Código de obra (char[5])
- Dirección (char[30])
- Provincia (1 a 24)
- Superficie (en metros cuadrados)
- Estado de ejecución:
  - 1: en proyecto
  - 2: proyecto aprobado en espera
  - 3: en ejecución
  - 4: terminada
  - 5: suspendida
- Activo (sí/no)

### `materiales.dat`
- Código de material (entero)
- Nombre (char[30])
- Marca (char[30])
- Tipo:
  - 1: obra gruesa
  - 2: techos
  - 3: aberturas
  - 4: revestimientos
  - 5: sanitarios
  - 6: electricidad
- Precio unitario
- Activo (sí/no)

### `compras.dat`
- Número de compra (entero)
- Número de proveedor
- Código de material
- Código de obra
- Cantidad
- Importe
- Fecha (día, mes, y año)
- Activo (sí/no)

> Las compras corresponden a los materiales utilizados para las obras registradas en el archivo `obras.dat`. Puede haber muchos registros para cada obra.

### `proveedores.dat`
- Número de proveedor (1 a 60) **// no puede haber un número de proveedor fuera de ese rango**
- Nombre
- Teléfono
- Dirección
- Provincia (1 a 24)
- Activo (sí/no)

---

## Preguntas

1. Generar un archivo con las compras realizadas este año. Cada registro debe tener el número de compra, el número de proveedor y el importe. (5 puntos).

2. Informar la provincia con más proveedores. (3 puntos).

3. Listar los materiales que pertenezcan a un tipo que se ingresa por teclado. (2 puntos).

---

## Desafío:

### Punto 2 modificado:

Informar la provincia con más proveedores entre los proveedores a los que se les haya hecho compras este año.
