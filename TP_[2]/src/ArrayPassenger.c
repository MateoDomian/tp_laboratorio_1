
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"



int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos){

    int retorno=-1;
    int buffer;
    do{

        if(pResultado != NULL && mensaje != NULL && msjError != NULL && min<= max && reintentos>0)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &buffer);

            if(buffer >= min && buffer <= max){
                *pResultado = buffer;
                retorno = 0;
                break;
            }else{
                printf("%s", msjError);
                reintentos--;
            }
        }
    }while(reintentos>=0);

    return retorno;
}

int initPassengers(Passenger list[], int len){

int retorno = 0;

	if(list != NULL && len > 0){

		for(int i = 0; i < len; i++){
			list[i].isEmpty = 1;
			retorno = 1;
			break;
		}

	}
	return retorno;
}

void mostrarPassengers(Passenger list[], int len){

	if(list != NULL && len > 0){

		printf("Passenger list: \n\n" );

		for(int i = 0; i < len; i++){
			printf("El nombre del pasajero es %s\n",list[i].name);
			printf("El apellido del pasajero es %s\n",list[i].lastname);
			printf("El precio del pasaje es %f\n",list[i].price);
			printf("El el codigo de vuelo %s\n",list[i].flycode);
			printf("El tipo de pasajero es %d\n",list[i].typePassenger);
			printf("El estado del vuelo es %d\n",list[i].statusFlight);
			printf("El id del pasajero actual es %d\n\n",list[i].id);
		}
	}
}

int addPassenger(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje){

		int retorno = 0;
		char nombreIngresado[51];
		char apellidoIngresado[51];
		char flycodeIngresado[10];

		float contadorPrecioPasaje = 0;
		float acumuladorPrecioPasaje = 0;

		if(list != NULL && len > 0){

			for(int i = 0; i < len; i++){
			retorno = 1;

					printf("Ingrese el nombre del pasajero\n");
					 scanf("%s", nombreIngresado);

					printf("Ingrese el apellido del pasajero\n");
					scanf("%s", apellidoIngresado);

					printf("Ingresa el precio del pasaje\n");
					scanf("%f", &list[i].price);

					printf("Ingrese el codigo de vuelo\n");
					scanf("%s", flycodeIngresado);

					printf("Ingrese el tipo de pasajero:\n1. Pasajero Menor\n2. Pasajero Adolescente\n3. Pasajero Adulto\n");
					scanf("%d", &list[i].typePassenger);

					printf("Ingrese el estado del vuelo:\n1. Vuelo activo\n2. Vuelo demorado\n");
					scanf("%d", &list[i].statusFlight);

					strcpy(list[i].name, nombreIngresado);
					strcpy(list[i].lastname, apellidoIngresado);
					strcpy(list[i].flycode, flycodeIngresado);

				list[i].isEmpty = 0;
				list[i].id = 1 + i;


				printf("El nombre del pasajero es %s\n",list[i].name);
				printf("El apellido del pasajero es %s\n",list[i].lastname);
				printf("El precio del pasaje es %f\n",list[i].price);
				printf("El tipo de pasajero es %d\n",list[i].typePassenger);
				printf("El estado del vuelo es %d\n",list[i].statusFlight);
				printf("El el codigo de vuelo %s\n",list[i].flycode);
				printf("El id del pasajero actual es %d\n\n\n",list[i].id);


				contadorPrecioPasaje = contadorPrecioPasaje + 1;
				acumuladorPrecioPasaje = acumuladorPrecioPasaje + list[i].price;
			}



			*contadorPasaje = contadorPrecioPasaje;
			*acumuladorPasaje = acumuladorPrecioPasaje;

		}

	return retorno;

}

int findPassengerById(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje){

	int menuModificar;
	int idModificar;
	int retorno = 0;
	int auxId;

	float acumuladorPrecioPasaje = 0;


	printf("Ingrese el id del pasajero a modificar");
	scanf("%d", &idModificar);

	for(int i = 0; i < len; i++){
			if(idModificar == list[i].id && list[i].isEmpty == 0){
				retorno = 1;
				auxId = i;
				break;
			}
		}

	if(list[auxId].isEmpty == 0){
		if(retorno == 1){
			do{
				printf("Introduzca el campo que desea modificar\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de Pasajero\n5.Estado del Vuelo\n6.Codigo de Vuelo\n7.Salir de modificar pasajero");
				scanf("%d", &menuModificar);

					switch(menuModificar){
					case 1:
						printf("El nombre actual es %s\n",list[auxId].name);
						printf("Ingrese el nombre nuevo");
						scanf("%s", list[auxId].name);
						printf("El nombre modificado es %s\n\n",list[auxId].name);
						break;
					case 2:
						printf("El apellido actual es %s\n",list[auxId].lastname);
						printf("Ingrese el apellido nuevo");
						scanf("%s", list[auxId].lastname);
						printf("El apellido modificado es %s\n\n",list[auxId].lastname);
						break;
					case 3:
						printf("El precio actual es %f\n",list[auxId].price);
						acumuladorPrecioPasaje = acumuladorPrecioPasaje - list[auxId].price;
						printf("Ingrese el precio nuevo");
						scanf("%f", &list[auxId].price);
						printf("El precio modificado es %f\n\n",list[auxId].price);
						acumuladorPrecioPasaje = acumuladorPrecioPasaje + list[auxId].price;
						break;
					case 4:
						printf("El tipo de pasajero actual es %d\n",list[auxId].typePassenger);
						printf("Ingrese el tipo de pasajero nuevo");
						scanf("%d", &list[auxId].typePassenger);
						printf("El tipo de pasajero modificado es %d\n\n",list[auxId].typePassenger);
						break;
					case 5:
						printf("El estado del vuelo actual es %d\n",list[auxId].statusFlight);
						printf("Ingrese el estado del vuelo nuevo");
						scanf("%d", &list[auxId].statusFlight);
						printf("El estado del vuelo modificado es %d\n\n",list[auxId].statusFlight);
						break;
					case 6:
						printf("El codigo de vuelo actual es %s\n",list[auxId].flycode);
						printf("Ingrese el codigo de vuelo nuevo");
						scanf("%s", list[auxId].flycode);
						printf("El codigo de vuelo modificado es %s\n\n",list[auxId].flycode);
						break;
						}
			}while(menuModificar == 7);
		}else{
			printf("Error, el pasajero que intenta modificar no se encuentra en nuestra base de datos");
		}

		*acumuladorPasaje = acumuladorPrecioPasaje;

	}
	return retorno;
}

void removePassenger(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje){

	int idModificar;
	int i;

	printf("Ingrese el id del pasajero que desea a eliminar\n");
	scanf("%d",&idModificar);

	for(i = 0; i < len; i++){
		if(idModificar == list[i].id){
			printf("El pasajero esta registrado y se procedera a eliminarlo de la lista\n");
			list[i].isEmpty = 1;
			*acumuladorPasaje = *acumuladorPasaje - list[i].price;
			*contadorPasaje = *contadorPasaje - 1;
			break;
		}
	}
	if(list[i].isEmpty == 1){
		printf("El pasajero ha sido dado de baja exitosamente\n");
	}
}

void sortPassengers(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje){

	int flagCambio;
	int flagCambioDos;
	int flagCambioTres;
	int i;

	char auxNombre[51];
	char auxApellido[51];
	float auxPrecio;
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	int auxEstadoVuelo;
	int auxId;
	int respuestaModoOrdenamiento;

	float promedio;
	int contadorSuperiorPromedio = 0;


	printf("Ingrese de que forma desea ordenar los datos:\n 1. Ascendente\n 2. Descendente");
	scanf("%d", &respuestaModoOrdenamiento);


	do{

		flagCambio = 0;

		if(respuestaModoOrdenamiento == 1){
			for(i = 0; i < len-1; i++){

						if(list[i].typePassenger > list[i+1].typePassenger){

							flagCambio = 1;

							strcpy(auxNombre, list[i].name);
							strcpy(list[i].name, list[i+1].name);
							strcpy(list[i+1].name, auxNombre);

							strcpy(auxApellido, list[i].lastname);
							strcpy(list[i].lastname, list[i+1].lastname);
							strcpy(list[i+1].lastname, auxApellido);

							auxPrecio = list[i].price;
							list[i].price = list[i+1].price;
							list[i+1].price = auxPrecio;

							strcpy(auxCodigoVuelo, list[i].flycode);
							strcpy(list[i].flycode, list[i+1].flycode);
							strcpy(list[i+1].flycode, auxCodigoVuelo);

							auxTipoPasajero = list[i].typePassenger;
							list[i].typePassenger = list[i+1].typePassenger;
							list[i+1].typePassenger = auxTipoPasajero;

							auxEstadoVuelo = list[i].statusFlight;
							list[i].statusFlight = list[i+1].statusFlight;
							list[i+1].statusFlight = auxEstadoVuelo;

							auxId = list[i].id;
							list[i].id = list[i+1].id;
							list[+1].id = auxId;
						}
				}
		}
		else{
			for(i = 0; i < len-1; i++){

				if(list[i].typePassenger < list[i+1].typePassenger){

					flagCambio = 1;

					strcpy(auxNombre, list[i].name);
					strcpy(list[i].name, list[i+1].name);
					strcpy(list[i+1].name, auxNombre);

					strcpy(auxApellido, list[i].lastname);
					strcpy(list[i].lastname, list[i+1].lastname);
					strcpy(list[i+1].lastname, auxApellido);

					auxPrecio = list[i].price;
					list[i].price = list[i+1].price;
					list[i+1].price = auxPrecio;

					strcpy(auxCodigoVuelo, list[i].flycode);
					strcpy(list[i].flycode, list[i+1].flycode);
					strcpy(list[i+1].flycode, auxCodigoVuelo);

					auxTipoPasajero = list[i].typePassenger;
					list[i].typePassenger = list[i+1].typePassenger;
					list[i+1].typePassenger = auxTipoPasajero;

					auxEstadoVuelo = list[i].statusFlight;
					list[i].statusFlight = list[i+1].statusFlight;
				    list[i+1].statusFlight = auxEstadoVuelo;

					auxId = list[i].id;
					list[i].id = list[i+1].id;
					list[+1].id = auxId;
				}
			}
		}
	}while(flagCambio == 1);

				printf("\n\nPasajeros Ordenados por tipo de pasajero\n");
				printf("***********************************************\n");
			for(i = 0; i < len; i++){
				printf("El nombre del pasajero es %s\n",list[i].name);
				printf("El apellido del pasajero es %s\n",list[i].lastname);
				printf("El precio del pasaje es %f\n",list[i].price);
				printf("El tipo de pasajero es %d\n",list[i].typePassenger);
				printf("El estado del vuelo es %d\n",list[i].statusFlight);
				printf("El el codigo de vuelo %s\n",list[i].flycode);
				printf("El id del pasajero actual es %d\n",list[i].id);
				printf("***********************************************\n");
			}


	do{

		flagCambioDos = 0;

		if(respuestaModoOrdenamiento == 1){
			for(i = 0; i < len-1; i++){

				if(strcmp(list[i].lastname,list[i+1].lastname)>0){
				                    flagCambioDos=1;

				                    auxEstadoVuelo=list[i].statusFlight;
				                    list[i].statusFlight=list[i+1].statusFlight;
				                    list[i+1].statusFlight=auxEstadoVuelo;

				                    auxPrecio=list[i].price;
				                    list[i].price=list[i+1].price;
				                    list[i+1].price=auxPrecio;

				                    auxId=list[i].id;
				                    list[i].id=list[i+1].id;
				                    list[i+1].id=auxId;

				                    auxTipoPasajero = list[i].typePassenger;
				                    list[i].typePassenger = list[i+1].typePassenger;
				                    list[i+1].typePassenger = auxTipoPasajero;

				                    strcpy(auxNombre,list[i].name);
				                    strcpy(list[i].name,list[i+1].name);
				                    strcpy(list[i+1].name,auxNombre);

				                    strcpy(auxApellido,list[i].lastname);
				                    strcpy(list[i].lastname,list[i+1].lastname);
				                    strcpy(list[i+1].lastname,auxApellido);

				                	strcpy(auxCodigoVuelo, list[i].flycode);
				                    strcpy(list[i].flycode, list[i+1].flycode);
				                	strcpy(list[i+1].flycode, auxCodigoVuelo);
				}
			}
		}
		else{
			for(i = 0; i < len-1; i++){

				if(strcmp(list[i].lastname,list[i+1].lastname)<0){
										flagCambioDos=1;

										auxEstadoVuelo=list[i].statusFlight;
										list[i].statusFlight=list[i+1].statusFlight;
										list[i+1].statusFlight=auxEstadoVuelo;

										auxPrecio=list[i].price;
										list[i].price=list[i+1].price;
										list[i+1].price=auxPrecio;

										auxId=list[i].id;
										list[i].id=list[i+1].id;
										list[i+1].id=auxId;

										auxTipoPasajero = list[i].typePassenger;
										list[i].typePassenger = list[i+1].typePassenger;
										list[i+1].typePassenger = auxTipoPasajero;

										strcpy(auxNombre,list[i].name);
										strcpy(list[i].name,list[i+1].name);
										strcpy(list[i+1].name,auxNombre);

										strcpy(auxApellido,list[i].lastname);
										strcpy(list[i].lastname,list[i+1].lastname);
										strcpy(list[i+1].lastname,auxApellido);

										strcpy(auxCodigoVuelo, list[i].flycode);
										strcpy(list[i].flycode, list[i+1].flycode);
										strcpy(list[i+1].flycode, auxCodigoVuelo);
				}
			}
		}




	}while(flagCambioDos == 1);

		printf("\n\nPasajeros Ordenados alfabeticamente\n");
		printf("***********************************************\n");
		for(i = 0; i < len; i++){
		printf("El nombre del pasajero es %s\n",list[i].name);
		printf("El apellido del pasajero es %s\n",list[i].lastname);
		printf("El precio del pasaje es %f\n",list[i].price);
		printf("El tipo de pasajero es %d\n",list[i].typePassenger);
		printf("El estado del vuelo es %d\n",list[i].statusFlight);
		printf("El el codigo de vuelo %s\n",list[i].flycode);
		printf("El id del pasajero actual es %d\n",list[i].id);
		printf("***********************************************\n");
	}



		do{

			flagCambioTres = 0;

			if(respuestaModoOrdenamiento == 1){
				for(i = 0; i < len-1; i++){


					if(strcmp(list[i].flycode,list[i+1].flycode)>0){

						flagCambioTres=1;

						auxEstadoVuelo=list[i].statusFlight;
						list[i].statusFlight=list[i+1].statusFlight;
						list[i+1].statusFlight=auxEstadoVuelo;

						auxPrecio=list[i].price;
						list[i].price=list[i+1].price;
						list[i+1].price=auxPrecio;

						auxId=list[i].id;
						list[i].id=list[i+1].id;
						list[i+1].id=auxId;

						strcpy(auxNombre,list[i].name);
						strcpy(list[i].name,list[i+1].name);
						strcpy(list[i+1].name,auxNombre);

						strcpy(auxApellido,list[i].lastname);
						strcpy(list[i].lastname,list[i+1].lastname);
						strcpy(list[i+1].lastname,auxApellido);

						auxTipoPasajero = list[i].typePassenger;
						list[i].typePassenger = list[i+1].typePassenger;
						list[i+1].typePassenger = auxTipoPasajero;

						strcpy(auxCodigoVuelo, list[i].flycode);
						strcpy(list[i].flycode, list[i+1].flycode);
						strcpy(list[i+1].flycode, auxCodigoVuelo);
					}

						}
			}
			else{

				for(i = 0; i < len-1; i++){
				if(strcmp(list[i].flycode, list[i+1].flycode) < 0){

					flagCambioTres=1;

					auxEstadoVuelo=list[i].statusFlight;
					list[i].statusFlight=list[i+1].statusFlight;
					list[i+1].statusFlight=auxEstadoVuelo;

					auxPrecio=list[i].price;
					list[i].price = list[i+1].price;
					list[i+1].price = auxPrecio;

					auxId=list[i].id;
					list[i].id = list[i+1].id;
					list[i+1].id = auxId;

					strcpy(auxNombre,list[i].name);
					strcpy(list[i].name,list[i+1].name);
					strcpy(list[i+1].name,auxNombre);

					strcpy(auxApellido,list[i].lastname);
					strcpy(list[i].lastname,list[i+1].lastname);
					strcpy(list[i+1].lastname,auxApellido);

					strcpy(auxCodigoVuelo, list[i].flycode);
					strcpy(list[i].flycode, list[i+1].flycode);
					strcpy(list[i+1].flycode, auxCodigoVuelo);

					auxTipoPasajero = list[i].typePassenger;
					list[i].typePassenger = list[i+1].typePassenger;
					list[i+1].typePassenger = auxTipoPasajero;
					}
				}
			}

			}while(flagCambioTres == 1);

			printf("\n\nPasajeros con vuelo ACTIVO Ordenados por codigo de vuelo\n");
			printf("***********************************************\n");
			for(i = 0; i < len; i++){
			printf("El nombre del pasajero es %s\n",list[i].name);
			printf("El apellido del pasajero es %s\n",list[i].lastname);
			printf("El precio del pasaje es %f\n",list[i].price);
			printf("El tipo de pasajero es %d\n",list[i].typePassenger);
			printf("El estado del vuelo es %d\n",list[i].statusFlight);
			printf("El el codigo de vuelo %s\n",list[i].flycode);
			printf("El id del pasajero actual es %d\n",list[i].id);
			printf("***********************************************\n");

		}

			float acumuladorPasajeLocal;
			float contadorPasajeLocal;

			acumuladorPasajeLocal = *acumuladorPasaje;
			contadorPasajeLocal = *contadorPasaje;

			promedio = (float)acumuladorPasajeLocal/contadorPasajeLocal;


			printf("El promedio del precio es %.2f\n", &promedio);

			for(i = 0; i < len; i++){
				if(list[i].price > promedio){
					contadorSuperiorPromedio++;
				}
			}
			printf("La cantidad de pasajes superiores al promedio es %d\n", contadorSuperiorPromedio);

	}

void cargaForzada(Passenger list[], int len){



	printf("***********************************************\n");
	printf("El nombre del pasajero es Mateo\n");
	printf("El apellido del pasajero es Domian\n");
	printf("El precio del pasaje es 15000\n");
	printf("El tipo de pasajero es 2\n");
	printf("El estado del vuelo es 1\n");
	printf("El el codigo de vuelo 452\n");
	printf("El id del pasajero actual es 1\n");
	printf("***********************************************\n");

	printf("***********************************************\n");
	printf("El nombre del pasajero es Carlos\n");
	printf("El apellido del pasajero es Campero\n");
	printf("El precio del pasaje es 45000\n");
	printf("El tipo de pasajero es 3\n");
	printf("El estado del vuelo es 1\n");
	printf("El el codigo de vuelo 653\n");
	printf("El id del pasajero actual es 2\n");
	printf("***********************************************\n");

	printf("***********************************************\n");
	printf("El nombre del pasajero es Martina\n");
	printf("El apellido del pasajero es Fernandez\n");
	printf("El precio del pasaje es 5500\n");
	printf("El tipo de pasajero es 3\n");
	printf("El estado del vuelo es 1\n");
	printf("El el codigo de vuelo 532\n");
	printf("El id del pasajero actual es 3\n");
	printf("***********************************************\n");

	printf("***********************************************\n");
	printf("El nombre del pasajero es Lucas\n");
	printf("El apellido del pasajero es Gonzales\n");
	printf("El precio del pasaje es 32200\n");
	printf("El tipo de pasajero es 1\n");
	printf("El estado del vuelo es 2\n");
	printf("El el codigo de vuelo 574\n");
	printf("El id del pasajero actual es 4\n");
	printf("***********************************************\n");

	printf("***********************************************\n");
	printf("El nombre del pasajero es Martin\n");
	printf("El apellido del pasajero es Artemi\n");
	printf("El precio del pasaje es 12500\n");
	printf("El tipo de pasajero es 2\n");
	printf("El estado del vuelo es 1\n");
	printf("El el codigo de vuelo 321\n");
	printf("El id del pasajero actual es 5\n");
	printf("***********************************************\n");
}

int isInt(char *punteroAux)
{
    int estaOk = -1;
    int i = 0;
    int stringlargo = strlen(punteroAux);


    while (i < stringlargo){
        if(*(punteroAux + i) < '0' || *(punteroAux + i) > '9')
        {
            break;
        }

        i++;

    }

    if(i == stringlargo)
    {
        estaOk = 0; //exito
    }

    return estaOk;
}

int getInt(int* punteroAux)
{
    char auxString[400];
    int estaOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *punteroAux = atoi(auxString); //to integer
        estaOk = 0; //exito
    }
    return estaOk;
}

int utn_getEntero(int* pEntero, int reintentos, char* msg, char*msgError, int min, int max)
{
    int estaOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && reintentos >= 0)
    {
        while(reintentos >= 0){
            reintentos--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                estaOk = 0; //exito
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }

    }
    return estaOk;
}

int isChar(char str[])
{

	int estaOk = 0; //exito

	for(int i = 0; str[i] != '\0'; i++)
	{
		//si no es espacio, si es menor a 'a' o mayor a 'z', si es menor a 'A' o mayor a 'Z', NO es letra:
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			estaOk = -1;
		}
	}

	return estaOk;

}

int getCadena(char* punteroAux, int limite)
{
    char auxString[4000];
    int estaOk = -1;

    if (punteroAux != NULL && limite > 0)
    {
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(punteroAux, auxString, limite);
            estaOk=0;
        }
    }

    return estaOk;
}
