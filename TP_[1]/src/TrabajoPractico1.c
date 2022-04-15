#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {

	setbuf(stdout, NULL);
	char respuesta;
	int precioLatam;
	int precioAerolineas;
	float tarjetaDebitoLatam;
	float tarjetaDebitoAerolineas;
	float tarjetaCreditoLatam;
	float tarjetaCreditoAerolineas;
	float bitcoinLatam;
	float bitcoinAerolineas;
	float kilometroLatam;
	float kilometroAerolineas;
	float diferenciaPrecioGuardado;
	int validacionKilometro;
	int validacionPreciosLatam;
	int validacionPreciosAerolinea;
	int kilometroGuardado;
	int flag = 0;

	respuesta = printf("Desea ingresar un vuelo? s / n");
	scanf("%c", &respuesta);

	while (respuesta == 's') {

		switch (menu()) {
		case 1:
			if(flag == 0){

			validacionKilometro = utn_getInt(&kilometroGuardado, "\nIngrese los kilometros", "\nError, ingrese nuevamente los kilometros!", 0, 100000, 2);

				if(validacionKilometro == 0){
					flag = 1;
				}
			}
			break;
		case 2:
			if(flag == 1){

			validacionPreciosLatam = utn_getInt(&precioLatam, "\nIngrese el precio de Latam Airlines:", "\nError, ingrese nuevamente el precio de Latam Airlines:", 0, 100000, 2);
			validacionPreciosAerolinea = utn_getInt(&precioAerolineas, "\nIngrese el precio de Aerolineas Argentinas:", "\nError, ingrese nuevamente el precio de Aerolineas Argentinas:", 0, 100000, 2);

				if(validacionPreciosLatam == 0 && validacionPreciosAerolinea == 0){
					flag = 2;
				}
			}
			break;
		case 3:
			if(flag == 2){
			tarjetaDebitoLatam = tarjetaDebito(precioLatam);
			tarjetaDebitoAerolineas = tarjetaDebito(precioAerolineas);
			tarjetaCreditoLatam = tarjetaCredito(precioLatam);
			tarjetaCreditoAerolineas = tarjetaCredito(precioAerolineas);
			bitcoinLatam = calcularBitcoin(precioLatam);
			bitcoinAerolineas = calcularBitcoin(precioAerolineas);
			kilometroLatam = precioXKm(kilometroGuardado, precioLatam);
			kilometroAerolineas = precioXKm(kilometroGuardado, precioAerolineas);
			diferenciaPrecioGuardado = diferenciaPrecio(precioAerolineas, precioLatam);
			printf("Se realizaron los calculos con exito, presiona el 4 para ver los resultados");
			flag = 3;
			}
			break;
		case 4:
			if(flag == 3){
			informarResultados(tarjetaDebitoLatam, tarjetaDebitoAerolineas, tarjetaCreditoLatam, tarjetaCreditoAerolineas, bitcoinLatam, bitcoinAerolineas, kilometroLatam, kilometroAerolineas, precioLatam, precioAerolineas, kilometroGuardado, diferenciaPrecioGuardado);
			flag = 4;
			}
			break;
		case 5:
			cargaForzada();
			break;
		case 6:
			respuesta = printf("Desea ingresar un vuelo? s / n");
			fflush(stdin);
			scanf("%c", &respuesta);
			break;
		}
	}
	return EXIT_SUCCESS;
}
