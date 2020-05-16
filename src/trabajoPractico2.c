/*
 ============================================================================
 Name        : trabajoPractico2.c
 Author      : LeandroCabeza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "empleado.h"
#define QTY 500




int main(void) {
	setbuf(stdout,NULL);
	Employee empleados[QTY];
	int respuesta ;
	int opcion;
	int legajo = 0  ;
	int flag = 1 ;
	char salirSub ;

	inicializarEmpleados(empleados,QTY);

	printf("\nBienvenido al operador de empleados , que tarea desea Realizar??\n");
		do
			{
				respuesta = utn_getNumero(&opcion,  "\n1-Alta Empleado "
													"\n2-Baja Empleado "
													"\n3-Modificar empleados"
													"\n4-Informes"
													"\n5-Salir\n",
													"\nERROR, las opciones validas estan del 1 al 6\n",1,5,5 );

		if (flag == 1) {
			printf(
					"\n Recorda :  que para poder operar con los empleados , es necesario que des de alta alguno.\n"
					"--------------------------------------------------------------------------------------------\n");
					altaEmpleado(empleados,QTY,legajo);
					legajo++;
					flag = 0;
		}else{
				if(respuesta == 0 )
				{
					switch(opcion)
					{
						case 1:
							altaEmpleado(empleados,QTY,legajo);
							printf("\nEl empleado fue dado de alta\n");
							flag = 0;
							break;
						case 2:
							bajaEmployee(empleados, QTY);
							printf("\nSe realizo la baja\n");
							break;
						case 3:
							modificarEmpleado(empleados, QTY);
							printf("\nSe modifico el empleado\n");
							break;
						case 4:
							printf("Informes \n");
								do {
									switch (subMenuInformes()) {
									case 1:
										ordenarEmpleados(empleados,QTY);
										mostrarTodosLosEmployees(empleados,QTY);
										break;
									case 2 :
										promedio(empleados,QTY);
										break;
									case 3:
										printf("\nConfirma Salida ?");
										fflush(stdin);
										salirSub = getchar();
										break;
									default:
										printf("Opcion Invalida");
									}
									system("pause");
								} while (salirSub == 'n');
								break;

						case 5:
							printf("\n***Hasta luego***\n");
							break;

					}
				}
			}
					}while(opcion != 5);
		return 0;
		}

