/*
 * empleado.c
 *
 *  Created on: 7 may. 2020
 *      Author: leand
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleado.h"




int inicializarEmpleados(Employee empleados[], int tam)
{
	int retorno=-1;
	    if(empleados!= NULL && tam>0)
	    {
	        for(;tam>0;tam--)
	        {
	        	empleados[tam-1].isEmpty=1;
	        }
	        retorno=0;
	    }
	    return retorno;
}



int buscarLibre(Employee empleado[], int tam)
{
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(empleado[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}


Employee nuevoEmpleado(int id,char name[],char lastName[], int salary,int sector)
{
	Employee nuevoEmpleado ;
	nuevoEmpleado.id = id;
	strcpy(nuevoEmpleado.name,name);
	strcpy(nuevoEmpleado.lastName,lastName);
	nuevoEmpleado.salary = salary ;
	nuevoEmpleado.sector = sector ;
	nuevoEmpleado.isEmpty = 0;

	return nuevoEmpleado;
}


int altaEmpleado(Employee empleado[], int tam, int legajo)
{
	int todoOk = 0;
	int indice;
	char name[50];
	char lastName[50];
	int salary;
	int sector;

	printf("***Datos a cargar del Empleado****\n\n");

	indice = buscarLibre(empleado, tam);

	if(indice == -1)
	{
		printf("Sistema Completo. No se pueden agregar mas empleados.\n");
		system("pause");
	}
	else
	{
		fflush(stdin);
		utn_getName("Ingrese el nombre: \n", "\nERROR: NOMBRE INCORRECTO\n", 0,20,5, name);
		fflush(stdin);
		utn_getName("Ingrese el Apellido: \n", "\nERROR: NOMBRE INCORRECTO\n", 0,20,5, lastName);
		fflush(stdin);
		utn_getNumero(&salary,"Ingrese el Salario: ", "\nERROR: SALARIO INCORRECTO\n",1000,500000,5);
		fflush(stdin);
		utn_getNumero(&sector, "Ingrese el sector: ", "\nERROR: SECTOR INCORRECTO\n",1,10,5);
		fflush(stdin);
		legajo ++ ;
		empleado[indice] = nuevoEmpleado(legajo, name, lastName, salary,sector);
		todoOk = 1;

	}
	return todoOk;
}


int findEmployeeById(int id , Employee empleados[],int tam)
{
	// Busca un alumno por legajo , compara que no este vacio (OSEA QUE TENGA ALGO CARGADO PREVIAMENTE) y luego evalua si es igual
	// al numero de legajo que le ingrese
	int indice = -1;
	for (int i = 0 ; i < tam ; i++)
	{
		if (empleados[i].isEmpty == 0 && empleados[i].id == id)
		{
			indice = i;
			break;
		}
	}
	return indice ;
}


void mostrarEmpleado(Employee empleado)
{
		printf("%d   %s    %s       %d    %d  \n\n",
		empleado.id,
		empleado.name,
		empleado.lastName,
		empleado.salary,
		empleado.sector
		);
	}



int mostrarEmployeePorId(Employee array[], int size,int idBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 && idBuscado>=0)
    {
        for(i=0;i<size;i++)
        {
        	if(array[i].isEmpty== 1)
        		continue;
            if(array[i].id==idBuscado )
            {
            	 printf("\n******************************************************\n "
            			 "ID: %d"
            			 "\nNombre: %s\n"
            			 "\nApellido: %s\n"
            			 "\nSalario: %d\n"
            			 "\nSector: %d\n",
            	        array[i].id,array[i].name,array[i].lastName,array[i].salary,array[i].sector);
            }
            	 else
                printf("\nEste ID no existe.\n");
        }
        retorno=0;
    }
    return retorno;
}


int mostrarTodosLosEmployees(Employee array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0 )
    {
    	for(i=0;i<size;i++)
    	{
    		if(array[i].isEmpty==1)
    		{
    			continue;
    		}
    		else
    		{
				printf(
						"\n******************************************************\n "
								"ID: %d"
								"\nNombre: %s\n"
								"\nApellido: %s\n"
								"\nSalario: %d\n"
								"\nSector: %d\n",
								array[i].id, array[i].name,	array[i].lastName, array[i].salary, array[i].sector);
		}
        retorno=0;
    	}
    }
    return retorno;
    }


int bajaEmployee(Employee empleados[],int tam )
{
	int todoOk = 0 ;
	int indice ;
	int id;
	char confirma ;

	system("cls");
	printf("**** BAJA EMPLEADO ***/ \n \n");

	printf("Ingrese ID :");
	scanf("%d",&id);

	indice = findEmployeeById(id,empleados,tam);

	if (indice == -1)
	{
		printf("\n No tenemos registrado ese ID \n");
		system("pause");
	}else {
		mostrarEmpleado( empleados[indice]);
		printf("\nConfirma eliminacion? :");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma =='s')
		{
			empleados[indice].isEmpty = 1 ;
			printf("\n\n Se ha eliminado el empleado \n");
			todoOk = 1 ;
		}
		else
		{
			printf("\n\n Se ha cancelado la baja \n");
		}
		system("pause");
	}
	return todoOk;
}


int ordenarEmpleados(Employee array[],int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Employee buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			retorno = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].lastName, array[i+1].lastName,50) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
				else if(strncmp(array[i].lastName, array[i+1].lastName,50) == 0)
				{
					if(array[i].sector > array[i+1].sector)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1] = buffer;
					}
				}
			}
			limite--;
		}while(flagSwap);
	}
	return retorno;
}

int modificarEmpleado(Employee empleados[],int tam)
{
	int todoOk = 0 ;
	int indice ;
	int id ;
	int opcion;

	system("cls");
	printf("****Modificar Empleado **** \n\n");

	printf("Ingrese el ID : ");
	scanf("%d",&id);

	indice = findEmployeeById(id,empleados,tam);

	if (indice == -1)
	{
		printf("\n No tenemos registrado ese id \n");
		system("pause");
	}
	else
	{
		mostrarEmpleado(empleados[indice]);
		printf("Modificar \n\n");
		printf("1-Nombre \n");
		printf("2-Apellido \n");
		printf("3-Salario \n");
		printf("2-Sector \n");

		printf("Ingrese Opcion");
		scanf("%d",&opcion);

		if(opcion == 1 )
		{
			utn_getName("\nIngrese Nombre del empleado: : ","\nError\n",1,51,1,empleados[indice].name);
			printf("Se actualizo el Nombre ");
			todoOk = 1 ;
		}
		else if (opcion == 2)
		{
			utn_getName("\nIngrese Apellido del musico: : ","\nError\n",1,51,1,empleados[indice].lastName);
			printf("Se actualizo el Apellido ");
			todoOk = 1;
		}else if (opcion == 3)
		{
			utn_getNumero(&empleados[indice].salary,"\nIngrese el Salario del empleado: ","\nError\n",1,500000,5);
			todoOk = 1;
		}else if (opcion == 4)
		{
			utn_getNumero(&empleados[indice].sector,"\nIngrese el sector del empleado: ","\nError\n",1,10,5);
						todoOk = 1;
		}
		else
		{
			printf("\nNo ingresaste una opcion Valida\n");
		}
		system("pause");
	}
	return todoOk ;
	}



void promedio(Employee empleados[],int size)
{
	int i ;
	float acumulador = 0 ;
	int contador = 0 ;
	float promedio = 0 ;
	int salarioMayorAlPromedio = 0;


	if (empleados != NULL && size > 0 ){
		for(i = 0 ; i < size ; i++){
			if (empleados[i].isEmpty == 0 ){
			acumulador = acumulador + empleados[i].salary ;
			contador ++;
		 }
		}
	for (i=0; i< size; i++)
		{
			if(empleados[i].salary > promedio && empleados[i].isEmpty == 0)
				{
					salarioMayorAlPromedio ++;
					}
				}

	promedio = (float)acumulador / contador ;

	printf ("\nEl monto TOTAL de salarios es : %.2f\n",acumulador);
	printf("\nSalario pormedio : %.2f\n",promedio);
	printf("\nEl numero de empleados que cobran mas que el promedio : %d \n",salarioMayorAlPromedio );
			}
}





