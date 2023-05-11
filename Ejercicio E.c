#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 100

void convertirTelefono(const char *telefono, char **nuevoTelefono) {
    // Asignar memoria para el nuevo número telefónico
    *nuevoTelefono = (char *)malloc(sizeof(char) * (strlen(telefono) + 8));

    // Copiar el código de país
    strncpy(*nuevoTelefono, "(", 2);
    strncat(*nuevoTelefono, telefono, 2);
    strncat(*nuevoTelefono, ")-", 3);
    
    // Copiar el siguiente dígito
    strncat(*nuevoTelefono, telefono + 2, 1);
    strncat(*nuevoTelefono, "-", 2);
    
    // Copiar el resto del número telefónico
    strncat(*nuevoTelefono, telefono + 3, strlen(telefono) - 3);
}

int main() {
    char numerosTelefonicos[MAX_NUMEROS][15];
    char *nuevosNumeros[MAX_NUMEROS];
    int numNumeros;

    // Obtener la cantidad de números telefónicos
    printf("Ingrese la cantidad de números telefónicos: ");
    scanf("%d", &numNumeros);

    // Leer los números telefónicos
    printf("Ingrese los números telefónicos:\n");
    for (int i = 0; i < numNumeros; i++) {
        scanf("%s", numerosTelefonicos[i]);
    }

    // Convertir y guardar los números telefónicos
    for (int i = 0; i < numNumeros; i++) {
        convertirTelefono(numerosTelefonicos[i], &nuevosNumeros[i]);
    }

    // Guardar los números telefónicos en un archivo
    FILE *archivo = fopen("numeros.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return 1;
    }

    for (int i = 0; i < numNumeros; i++) {
        fprintf(archivo, "Número telefónico: %s\n", numerosTelefonicos[i]);
        fprintf(archivo, "Nueva cadena: %s\n\n", nuevosNumeros[i]);

        // Liberar la memoria asignada para cada nuevo número telefónico
        free(nuevosNumeros[i]);
    }

    fclose(archivo);
    printf("Los números telefónicos se han guardado en el archivo 'numeros.txt'.\n");

    return 0;
}
