#include <stdio.h>

#define MAX_NOMBRE 50
#define MAX_CEDULA 30
#define MAX_TIPO 30
#define MAX_EDAD 30
#define MAX_FAMILIAR 30

void ingresarDatosFacturacion(const char *ID, const char *NOMBRE, const char *TIPO, const char *EDAD, const char *FAMILIAR, float *cantidad, float *precio, float *subtotal, int cantidadProductos, float total) {
	FILE *file = fopen("factura.txt", "w"); // Open the file in write mode
	if (file == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return;
	}
	
	fprintf(file, "############Datos de facturacion ##########\n");
	fprintf(file, "ID de la mascota: %s\n", ID);
	
	fprintf(file, " ** FACTURA **\n");
	fprintf(file, "PRODUCTO\t\tCANTIDAD\tVALOR\t\tUNITARIO\n");
	for (int i = 0; i < cantidadProductos; i++) {
		fprintf(file, "%d\t\t\t%.1f\t\t%.2f\t\t%.2f\n", i+1, cantidad[i], precio[i], subtotal[i]);
	}
	
	fprintf(file, "El total es %.2f\n", total);
	fprintf(file, "Gracias por venir\n");
	
	fclose(file); // Close the file
}

void imprimirFactura(const char *ID, float *cantidad, float *precio, float *subtotal, int cantidadProductos, float total) {
	printf("############Datos de facturacion ##########\n");
	printf("ID de la mascota: %s\n", ID);
	
	printf(" ** FACTURA **\n");
	printf("PRODUCTO\t\tCANTIDAD\tVALOR\t\tUNITARIO\n");
	for (int i = 0; i < cantidadProductos; i++) {
		printf("%d\t\t\t%.1f\t\t%.2f\t\t%.2f\n", i+1, cantidad[i], precio[i], subtotal[i]);
	}
	
	printf("El total es %.2f\n", total);
	printf("Gracias por venir\n");
}

int main() {
	char ID[MAX_CEDULA];
	char NOMBRE[MAX_NOMBRE];
	char TIPO[MAX_TIPO];
	char EDAD[MAX_EDAD];
	char FAMILIAR[MAX_FAMILIAR];
	float cantidad[MAX_FAMILIAR];
	float precio[MAX_FAMILIAR];
	float subtotal[MAX_FAMILIAR];
	int cantidadProductos = 0;
	float total = 0;
	char opcion;
	char SN;
	
	do {
		printf("Que desea el dia de hoy?\n");
		printf("a) Ingresar mascota\n");
		printf("b) Servicio\n");
		printf("c) Imprimir factura\n");
		printf("d) Salir\n");
		scanf(" %c", &SN);
		
		switch (SN) {
		case 'a':
			printf("ID de la mascota: ");
			scanf("%s", ID);
			printf("Nombre de la mascota: ");
			scanf("%s", NOMBRE);
			printf("tipo:");
			scanf("%s", TIPO);
			printf("edad:");
			scanf("%s", EDAD);
			printf("nombre del dueño:");
			scanf("%s", FAMILIAR);
			printf("registro completo\n");
			break;
		case 'b':
			printf("***ELIJA un servicio***\n");
			printf("ID:1 nombre:peluqueria descripcion: baño,corte de pelo y uñas precio($15)\n");
			printf("ID:2 nombre:veterinario descripcion:chequeo general precio($20)\n");
			printf("ID:3 nombre:vacunacion descripcion:vacunas precio($10)\n");
			printf("ID:4 nombre:desparacitacion descripcion: se desparacita al animal precio($18)\n");
			printf("ID:5 nombre:hotel  descripcion:se cuida al animal x noche precio($20)\n");
			scanf(" %c", &opcion);
			
			float *producto_cantidad = &cantidad[cantidadProductos];
			float *producto_precio = &precio[cantidadProductos];
			float *producto_subtotal = &subtotal[cantidadProductos];
			
			switch (opcion) {
			case '1':
				printf("Ingrese la cantidad: ");
				scanf("%f", producto_cantidad);
				*producto_precio = 15;
				break;
			case '2':
				printf("Ingrese la cantidad: ");
				scanf("%f", producto_cantidad);
				*producto_precio = 20;
				break;
			case '3':
				printf("Ingrese la cantidad: ");
				scanf("%f", producto_cantidad);
				*producto_precio = 10;
				break;
			case '4':
				printf("Ingrese la cantidad: ");
				scanf("%f", producto_cantidad);
				*producto_precio = 18;
				break;
			case '5':
				printf("Ingrese la cantidad: ");
				scanf("%f", producto_cantidad);
				*producto_precio = 20;
				break;
			default:
				printf("Opcion invalida\n");
				break;
			}
			
			*producto_subtotal = *producto_cantidad * *producto_precio;
			total += *producto_subtotal;
			cantidadProductos++;
			
			break;
		case 'c':
			ingresarDatosFacturacion(ID, NOMBRE, TIPO, EDAD, FAMILIAR, cantidad, precio, subtotal, cantidadProductos, total);
			imprimirFactura(ID, cantidad, precio, subtotal, cantidadProductos, total);
			return 0;
		default:
			break;
		}
	} while (SN != 'd');
	
	printf("Gracias por venir\n");
	
	return 0;
}

