
/*----------MENU-----------*/
int menu();

/*----------INGRESO KM-----------*/
int kilometro();

/*----------PEDIR VUELOS-----------*/
float pedirVuelo(float *y, float *z);

/*----------METODOS DE PAGO-----------*/

/*----TARJETA DEBITO----*/
float tarjetaDebito(int precio);
/*----TARJETA CREDITO----*/
float tarjetaCredito(int precio);
/*----BITCOIN----*/
float calcularBitcoin(int precio);
/*----PRECIOXKM----*/
float precioXKm(float kilometro, int precio);
/*----DIFERENCIA DE PRECIO----*/
float diferenciaPrecio(int aerolineas, int latam);

/*----------MOSTRAR RESULTADOS-----------*/
void informarResultados(float tarjetaDebitoLatam, float tarjetaDebitoAerolineas,
		float tarjetaCreditoLatam, float tarjetaCreditoAerolineas, float bitcoinLatam, float bitcoinAerolineas,
		float kilometroLatam, float kilometroAerolineas, int precioLatam, int precioAerolineas, int kilometroGuardado, float diferenciaPrecioGuardado);

/*----------CARGA FORZADA-----------*/
void cargaForzada();

/*----------CARGA FORZADA-----------*/

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


#ifndef CALCULOS_H_
#define CALCULOS_H_

#endif /* CALCULOS_H_ */
