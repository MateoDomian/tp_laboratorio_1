/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Mateo
 */

typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

typedef struct{
	int typePassenger;
	char description[25];

}tipoPasajero;


int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);
int initPassengers(Passenger list[], int len);
int searchFree(Passenger list[], int len);
int addPassenger(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje);
int findPassengerById(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje);
void removePassenger(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje);
void sortPassengers(Passenger list[], int len, float* contadorPasaje, float* acumuladorPasaje);
void cargaForzada(Passenger list[], int len);
int isInt(char *punteroAux);
int getInt(int* punteroAux);
int utn_getEntero(int* pEntero, int reintentos, char* msg, char*msgError, int min, int max);
int isChar(char str[]);
int getCadena(char* punteroAux, int limite);



#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#endif /* ARRAYPASSENGER_H_ */
