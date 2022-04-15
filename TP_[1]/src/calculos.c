
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

/*----------MENU-----------*/
int menu() {

	int opcion;

	printf("\n\n\n Menu, ingrese un numero para seguir\n");
	printf("\n 1. Ingresar kilometros");
	printf("\n 2. Ingresar precios de los vuelos");
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar resultados");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir");
	printf("\n Ingrese el numero que desea:\n\n");
	scanf("%d", &opcion);

	return opcion;
}

/*----------INGRESO KM-----------*/

int kilometro() {

	int numero;

	printf("Ingrese la cantidad de km:");
	scanf("%d", &numero);

	return numero;
}

/*----------PEDIR VUELOS-----------*/

float pedirVuelo(float *y, float *z) {

	float precioLatam;
	float precioAerolineas;
	int funciona = 0;

	if (y != NULL && z != NULL) {

		printf("Ingrese el precio de Latam:");
		scanf("%f", &precioLatam);

		*y = precioLatam;

		printf("Ingrese el precio de Aerolineas:");
		scanf("%f", &precioAerolineas);

		*z = precioAerolineas;

		funciona = 1;
	}

	return funciona;
}

/*----------METODOS DE PAGO-----------*/
/*------TARJETA DEBITO------*/

float tarjetaDebito(int precio) {
	int descuento;
	float precioFinalDescuento;

	descuento = precio * 0.1;
	precioFinalDescuento = precio - descuento;

	return precioFinalDescuento;
}

/*------TARJETA CREDITO------*/
float tarjetaCredito(int precio) {
	int interes;
	float precioFinalInteres;

	interes = precio * 0.25;
	precioFinalInteres = precio + interes;

	return precioFinalInteres;
}

/*------BITCOIN------*/
float calcularBitcoin(int precio) {
	float btc = 4606954.55;
	float btcFinal;

	btcFinal = precio / btc;

	return btcFinal;
}

/*------PRECIO X KM------*/

float precioXKm(float kilometro, int precio) {
	float precioKm;

	precioKm = precio / kilometro;

	return precioKm;
}

/*------DIFERENCIA DE PRECIO------*/

float diferenciaPrecio(int aerolineas, int latam) {

	float minimo;
	float maximo;
	float dif;

	if (aerolineas > latam) {
		maximo = aerolineas;
		minimo = latam;
	} else {
		maximo = latam;
		minimo = aerolineas;
	}

	dif = maximo - minimo;

	return dif;
}

/*----------MOSTRAR RESULTADOS-----------*/

void informarResultados(float tarjetaDebitoLatam, float tarjetaDebitoAerolineas,
		float tarjetaCreditoLatam, float tarjetaCreditoAerolineas, float bitcoinLatam, float bitcoinAerolineas,
		float kilometroLatam, float kilometroAerolineas, int precioLatam, int precioAerolineas, int kilometroGuardado, float diferenciaPrecioGuardado) {
	printf("La cantidad de kilometros: %d", kilometroGuardado);
	printf("\nLatam: %d", precioLatam);
	printf("\n a) Precio con tarjeta de débito: %.2f", tarjetaDebitoLatam);
	printf("\n b) Precio con tarjeta de crédito: %.2f", tarjetaCreditoLatam);
	printf("\n c) Precio pagando con bitcoin : %f", bitcoinLatam);
	printf("\n d) Precio unitario: %.2f", kilometroLatam);
	printf("\nAerolíneas: %d", precioAerolineas);
	printf("\n a) Precio con tarjeta de débito: %.2f", tarjetaDebitoAerolineas);
	printf("\n b) Precio con tarjeta de crédito: %.2f", tarjetaCreditoAerolineas);
	printf("\n c) Precio pagando con bitcoin : %f", bitcoinAerolineas);
	printf("\n d) Precio unitario: %.2f", kilometroAerolineas);
	printf("\n La diferencia de precio es : %.2f", diferenciaPrecioGuardado);

}

/*----------CARGA FORZADA-----------*/

void cargaForzada(){

	printf("KMs Ingresados: 7090 km");
	printf("\n Latam: 159339");
	printf("\n a) Precio con tarjeta de débito: %.2f", tarjetaDebito(159339));
	printf("\n b) Precio con tarjeta de crédito: %.2f", tarjetaCredito(159339));
	printf("\n c) Precio pagando con bitcoin : %f", calcularBitcoin(159339));
	printf("\n d) Precio unitario: %.2f", precioXKm(7090, 159339));
	printf("\nAerolíneas: 162965");
	printf("\n a) Precio con tarjeta de débito: %.2f", tarjetaDebito(162965));
	printf("\n b) Precio con tarjeta de crédito: %.2f", tarjetaCredito(162965));
	printf("\n c) Precio pagando con bitcoin : %f", calcularBitcoin(162965));
	printf("\n d) Precio unitario: %.2f", precioXKm(7090, 162965));
	printf("\n La diferencia de precio es : %.2f", diferenciaPrecio(162965, 159339));

}

/*----------VALIDACIONES-----------*/

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){

	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

		do{

	    printf("%s", mensaje);
	    scanf("%d", &buffer);

			if(buffer >= minimo && buffer <= maximo){
				*pResultado = buffer;
				retorno = 0;
				break;
				}
		printf("%s", mensajeError);
		reintentos--;

	    }while(reintentos>= 0);

	    }

	return retorno;
}
























