/*
 * empleado.h
 *
 *  Created on: 7 may. 2020
 *      Author: leand
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	int salary;
	int sector;
	int isEmpty;

} Employee;

/**
 * \brief  Inicializar el array , poniendo un 1 en todos los isEmpty
 * \param empleados array de empleados
 * \param tam tamanio del array.
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 */
int inicializarEmpleados(Employee empleados[],int tam);
/**
 * \brief Busca la primer posicion del array libre.
 * \param empleado array de empleados
 * \param tam tamanio del array de empleados
 * \return Retorna el indice de la posicion libre.
 */
int buscarLibre(Employee empleado[], int tam);
/**
 * \brief Carga un nuevo empleado
 * \param id id del empleado
 * \param name nombre del empleado
 * \param lastName apellido del empleado
 * \param salary salario del empleado
 * \param sector sector del empleado
 * \return Retorna un empleado con los datos cargados.
 */
Employee nuevoEmpleado(int id,char name[],char lastName[], int salary , int sector );
/**
 * \brief Da de alta un empleado en una posicion del array
 * \param empleado Array de empleados
 * \param tam Tamanio del array
 * \param legajo Posicion a ser actualizada
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 *
 */
int altaEmpleado(Employee empleado[], int tam, int legajo);
/**
 * \brief Busca un empleado por su ID.
 * \param id id del empleado a buscar
 * \param empleados array de empleados
 * \param tam tamanio del array
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int findEmployeeById(int id , Employee empleados[],int tam);
/**
 * \brief Muestra un empleado ingresado por parametro
 * \param empleado empleado printeado
 *  \return no retorna nada.
 */
void mostrarEmpleado(Employee x);
/**
 * \brief Muestra un empleado por su ID
 * \param empleados array de empleados
 * \param size tamanio del array
 * \param idBuscado id del empleado a ser mostrado
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int mostrarEmployeePorId(Employee array[], int size,int idBuscado);
/**
 * \brief Muestra todos los empleados
 * \param array array de empleados
 * \param size tamanio del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 */
int mostrarTodosLosEmployees(Employee array[], int size);
/**
 * \brief Da de baja un empleado
 * \param empleados Array de empleados a ser actualizado
 * \param tam tamanio del array de empleados
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int bajaEmployee(Employee empleados[],int tam );
/**
 * \brief Ordenar el array de empleados por apellido y si es necesario sector
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 */
int ordenarEmpleados(Employee array[],int limite);
/**
 * \brief Modifica los datos de un empleado seleccionado por su ID
 * \param empleados Array de empleados a ser actualizado
 * \param tam tamanio del array de empleados
 * \return Retorna 1 (EXITO) o 0 (ERROR)
 */
int modificarEmpleado(Employee empleados[],int tam);
/**
 * \brief Calcula los datos de un array de empleados , imprime el total de los salarios , el promedio y cuantos empleados cobran mas del promedio
 * \param empleados Array de empleados a ser analizado
 * \param size tamanio del array de empleados
 * \return no retorna nada
 */
void promedio(Employee empleado[],int size);



#endif /* EMPLEADO_H_ */
