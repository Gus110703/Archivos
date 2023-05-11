#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CADENA 100
void validarActividad(char *fechaHoy, char *cadena, char *mensaje);
void guardarEnArchivo(char *cadena, char *mensaje);
int main() {
    int n;
    char fechaHoy[MAX_CADENA];
    printf("Fecha de hoy: ");
    fgets(fechaHoy, sizeof(fechaHoy), stdin);
    fechaHoy[strcspn(fechaHoy, "\n")] = '\0'; // Eliminar el salto de línea al final de la fecha
    printf("Ingrese la cantidad de cadenas de caracteres: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char *cadena = (char *)malloc(MAX_CADENA * sizeof(char));
        char *mensaje = (char *)malloc(MAX_CADENA * sizeof(char));
        printf("Cadena %d: ", i + 1);
        fgets(cadena, MAX_CADENA, stdin);
        cadena[strcspn(cadena, "\n")] = '\0';
        validarActividad(fechaHoy, cadena, mensaje);
        guardarEnArchivo(cadena, mensaje);
        free(cadena);
        free(mensaje);
    }
    return 0;
}
void validarActividad(char *fechaHoy, char *cadena, char *mensaje) {
    char fechaCadena[MAX_CADENA];
    char concepto[MAX_CADENA];
    int i = 0;
    int j = 0;
    while (cadena[i] != ' ') {
        fechaCadena[i] = cadena[i];
        i++;
    }
    fechaCadena[i] = '\0';
    i++; 
    while (cadena[i] != '\0') {
        concepto[j] = cadena[i];
        i++;
        j++;
    }
    concepto[j] = '\0';
    if (strcmp(fechaHoy, fechaCadena) == 0) {
        strcpy(mensaje, "Actividad válida");
    } else {
        strcpy(mensaje, "Actividad no válida");
    }
}
void guardarEnArchivo(char *cadena, char *mensaje) {
    FILE *archivo = fopen("actividades.txt", "a"); // Abrir el archivo en modo de agregado
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "Cadena: %s\n", cadena);
    fprintf(archivo, "Resultado: %s\n", mensaje);
    fprintf(archivo, "\n");
    fclose(archivo);
}
