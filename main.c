#include <stdio.h>

#define MAX_NOMBRE 50
#define MAX_CEDULA 30
#define MAX_TIPO 30
#define MAX_EDAD 30
#define MAX_FAMILIAR 30
#define MAX_LINE_SIZE 100

void ingresarDatosFacturacion(const char *ID, const char *NOMBRE, const char *TIPO, const char *EDAD, const char *FAMILIAR, float *cantidad, float *precio, float *subtotal, int cantidadProductos, float total) {
	FILE *file = fopen("factura.txt", "a"); // Abrir el archivo en modo append
	if (file == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return;
	}
	
	fprintf(file, "############Datos de facturacion ##########\n");
	fprintf(file, "ID de la mascota: %s\n", ID);
	
	fprintf(file, " * FACTURA *\n");
	fprintf(file, "PRODUCTO\t\tCANTIDAD\tVALOR\t\tUNITARIO\n");
	for (int i = 0; i < cantidadProductos; i++) {
		fprintf(file, "%d\t\t\t%.1f\t\t%.2f\t\t%.2f\n", i+1, cantidad[i], precio[i], subtotal[i]);
	}
	
	fprintf(file, "El total es %.2f\n", total);
	fprintf(file, "Gracias por venir\n");
	
	fclose(file);
}

void guardarFacturaEnArchivo(const char *ID, float *cantidad, float *precio, float *subtotal, int cantidadProductos, float total) {
	FILE *file = fopen("factura.txt", "a");
	if (file == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return;
	}
	
	fprintf(file, "############Datos de facturacion ##########\n");
	fprintf(file, "ID de la mascota: %s\n", ID);
	
	fprintf(file, " * FACTURA *\n");
	fprintf(file, "PRODUCTO\t\tCANTIDAD\tVALOR\t\tUNITARIO\n");
	for (int i = 0; i < cantidadProductos; i++) {
		fprintf(file, "%d\t\t\t%.1f\t\t%.2f\t\t%.2f\n", i+1, cantidad[i], precio[i], subtotal[i]);
	}
	
	fprintf(file, "El total es %.2f\n", total);
	fprintf(file, "Gracias por venir\n");
	
	fclose(file);
}

void imprimirFactura(const char *ID, float *cantidad, float *precio, float *subtotal, int cantidadProductos, float total) {
	printf("############Datos de facturacion ##########\n");
	printf("ID de la mascota: %s\n", ID);
	
	printf(" * FACTURA *\n");
	printf("PRODUCTO\t\tCANTIDAD\tVALOR\t\tUNITARIO\n");
	for (int i = 0; i < cantidadProductos; i++) {
		printf("%d\t\t\t%.1f\t\t%.2f\t\t%.2f\n", i+1, cantidad[i], precio[i], subtotal[i]);
	}
	
	printf("El total es %.2f\n", total);
	printf("Gracias por venir\n");
	
	guardarFacturaEnArchivo(ID, cantidad, precio, subtotal, cantidadProductos, total); // Guardar factura en el archivo
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
		case 'a': {
			FILE *f1;
			f1 = fopen("mascota.txt", "w");
			
			if (f1 == NULL) {
				printf("No se pudo abrir el archivo.\n");
				return 1;
			}
			
			printf("ID de la mascota: ");
			scanf("%s", ID);
			printf("Nombre de la mascota: ");
			scanf("%s", NOMBRE);
			printf("Tipo: ");
			scanf("%s", TIPO);
			printf("Edad: ");
			scanf("%s", EDAD);
			printf("Nombre del dueño: ");
			scanf("%s", FAMILIAR);
			
			fprintf(f1, "ID de la mascota: %s\n", ID);
			fprintf(f1, "Nombre de la mascota: %s\n", NOMBRE);
			fprintf(f1, "Tipo: %s\n", TIPO);
			fprintf(f1, "Edad: %s\n", EDAD);
			fprintf(f1, "Nombre del dueño: %s\n", FAMILIAR);
			
			fclose(f1);
			
			printf("Registro completo.\n");
			
			break;
		}
		
		case 'b': {
			FILE *f2;
			f2 = fopen("servicios.txt", "r");
			if (f2 == NULL) {
				printf("No se pudo abrir el archivo de servicios.\n");
				return 1;
			}
			
			char linea[MAX_LINE_SIZE];
			while (fgets(linea, MAX_LINE_SIZE, f2) != NULL) {
				printf("%s\n", linea);
			}
			
			fclose(f2);
			
			printf("Ingrese la opción: \n");
			scanf(" %c", &opcion);
			
			while (opcion < '1' || opcion > '5') {
				printf("Opcion invalida\n");
				printf("Ingrese la opción: ");
				scanf(" %c", &opcion);
			}
			
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
				break;
			}
			
			*producto_subtotal = *producto_cantidad * *producto_precio;
			total += *producto_subtotal;
			cantidadProductos++;
			
			break;
		}
		
		case 'c':
			ingresarDatosFacturacion(ID, NOMBRE, TIPO, EDAD, FAMILIAR, cantidad, precio, subtotal, cantidadProductos, total);
			break;
			
		default:
			break;
		}
	} while (SN != 'd');
	
	imprimirFactura(ID, cantidad, precio, subtotal, cantidadProductos, total); // Imprimir factura al salir
	
	printf("Gracias por venir\n");
	
	return 0;
}
