#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscarPalabras(int longitud) {
FILE* archivo = fopen("texto.txt", "r");
if (archivo == NULL) {
printf("No se pudo abrir el archivo.\n");
return;
}

char palabra[100];

printf("Palabras de longitud %d encontradas:\n", longitud);

while (fscanf(archivo, "%s", palabra) != EOF) {
if (strlen(palabra) == longitud) {
printf("%s\n", palabra);
}
}

fclose(archivo);
}

int main() {
int longitud;

printf("Ingrese la longitud de las palabras a buscar: ");
scanf("%d", &longitud);

buscarPalabras(longitud);

return 0;
}