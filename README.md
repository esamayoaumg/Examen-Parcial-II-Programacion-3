# Examen-Parcial-II-Programacion-3

## Estructuras de Datos

**Estudiante:** Elder Geovani Samayoa Esquivel  
**Carné:** 9941-24-10076  
**Fecha de entrega:** 26/04/2026  

## 1. Descripción del programa
El presente programa consiste en un sistema de gestión y clasificación de datos dinámicos desarrollado en C++. El software permite capturar números enteros e integrarlos en diversas estructuras de datos lineales y no lineales mediante el uso de punteros y administración de memoria dinámica.

## 2. Estructuras de datos utilizadas
El sistema implementa de manera manual las siguientes estructuras:

* **Pila (Stack):** Almacenamiento de números impares positivos.
* **Cola (Queue):** Almacenamiento de números pares positivos.
* **Lista simplemente enlazada:** Gestión de valores negativos.
* **Lista doblemente enlazada:** Registro de historial (valor, destino y orden de ingreso).
* **Árbol Binario de Búsqueda (BST):** Organización jerárquica de los datos positivos para su posterior recorrido y consulta.

## 3. Lógica del sistema
El flujo de información se basa en las siguientes reglas de negocio:

* **Clasificación automática:** Los datos se distribuyen en las estructuras según su paridad y signo. Los valores iguales a cero son rechazados.
* **Construcción de BST:** El árbol se construye únicamente a petición del usuario extrayendo los datos válidos del historial, cumpliendo con la restricción de construcción diferida.
* **Procesamiento de negativos:** Se incluye un módulo para filtrar y eliminar de la lista simple los nodos cuya magnitud sea inferior a 10.
* **Reorganización:** Opción para vaciar estructuras lineales hacia listas auxiliares y reconstruir el árbol jerárquico.

## 4. Instrucciones de ejecución
1. Compilar el código fuente en un entorno compatible con C++.
2. Al ejecutar el programa, el encabezado mostrará los datos del estudiante.
3. Utilizar el menú principal para ingresar datos y navegar por las diferentes opciones de visualización y procesamiento.
4. Antes de finalizar, el sistema permite visualizar estadísticas generales sobre los datos procesados.

## 5. Requisitos técnicos cumplidos
* Uso de memoria dinámica (operadores new y delete).
* Implementación de nodos mediante estructuras (struct).
* Desarrollo de funciones de búsqueda y recorridos (InOrden, PreOrden, PostOrden).
* Validación de entradas y manejo de estructuras vacías.
