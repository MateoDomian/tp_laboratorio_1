
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#define MAX 5



int main(void) {

	setbuf(stdout, NULL);

	int respuestaDelMenu;
	int opcionDelUsuario;
	int retorno;
	int retornoUno;
	float contador;
	float acumulador;

	Passenger pasajeros[MAX];

	retorno = initPassengers(pasajeros, MAX);

	do{
		respuestaDelMenu = getNumero(&opcionDelUsuario, "Ingrese una de las opciones:\n 1. Alta  \n 2. Modificar \n 3. Baja: \n 4. Informar:\n 5. Carga Forzada:  \n 6. Salir\n\n\n", "reingrese la opcion elegida",1,5,3);
			if(respuestaDelMenu == 0){
				switch(opcionDelUsuario){
					case 1:
						if(retorno == 1){
								retornoUno = addPassenger(pasajeros, MAX, &contador, &acumulador);

						}
						else{
							printf("Error, no hay espacio disponible");
						}

						break;
					case 2:
						if(retornoUno == 1){
							findPassengerById(pasajeros, MAX, &contador, &acumulador);
						}
						else{
							printf("Error, ingrese un pasajero antes\n\n");
						}
						break;
					case 3:
						if(retornoUno == 1){
							removePassenger(pasajeros, MAX, &contador, &acumulador);
						}
						else{
							printf("Error, ingrese un pasajero antes\n\n");
						}
						break;
					case 4:
						if(retornoUno == 1){
							sortPassengers(pasajeros, MAX, &contador, &acumulador);
						}
						else{
							printf("Error, ingrese un pasajero antes\n\n");
						}
						break;
					case 5:
						cargaForzada(pasajeros, MAX);
						break;


					}
				}

	}while(opcionDelUsuario != 6);



	return EXIT_SUCCESS;
}



