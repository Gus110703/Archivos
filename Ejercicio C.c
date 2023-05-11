#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contarVocalesMayusculas(const char *cadena) {
int contador = 0;
int longitud = strlen(cadena);

for (int i = 0; i < longitud; i++) {
char caracter = cadena[i];
if (isupper(caracter) && strchr("AEIOU", caracter) != NULL) {
contador++;
}
}

return contador;
}

void encontrarPalabraMaxVocales(const char *cadena, char *palabraMaxVocales) {
int maxVocales = 0;
char *token;
char copiaCadena[strlen(cadena) + 1];
strcpy(copiaCadena, cadena);


token = strtok(copiaCadena, " ");

while (token != NULL) {
int numVocales = contarVocalesMayusculas(token);

if (numVocales > maxVocales) {
maxVocales = numVocales;
strcpy(palabraMaxVocales, token);
}


token = strtok(NULL, " ");
}
}

int main() {
int n;
printf("Ingrese el número de cadenas: ");
scanf("%d", &n);
fflush(stdin);

FILE *archivo = fopen("resultado.txt", "w");

for (int i = 0; i < n; i++) {
char cadena[100];
printf("Ingrese una cadena: ");
fflush(stdin);
fgets(cadena, sizeof(cadena), stdin);


cadena[strcspn(cadena, "\n")] = '\0';

char palabraMaxVocales[100];
encontrarPalabraMaxVocales(cadena, palabraMaxVocales);

printf("De la cadena \"%s\", \"%s\" tiene %d vocales.\n", cadena, palabraMaxVocales, contarVocalesMayusculas(palabraMaxVocales));


fprintf(archivo, "De la cadena \"%s\", \"%s\" tiene %d vocales.\n", cadena, palabraMaxVocales, contarVocalesMayusculas(palabraMaxVocales));
}

fclose(archivo);

printf("Los resultados se han guardado en el archivo \"resultado.txt\".\n");

return 0;
}