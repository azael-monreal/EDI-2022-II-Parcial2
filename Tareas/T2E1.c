/*
 * Realice un programa en C que pida una lista de nombres al usuario, además solicite otro,
 * y regrese el índice donde se encuentra el nombre y si no regrese un –1.
 *
 * Requerimientos:
 * 	Realice una función para solicitar los nombres al usuario.
 * 	Realice una función para buscar el nombre dentro de la lista.
 * 	La función deberá regresar un 1 si encontró el nombre y un 0 si no.
 *
 * Ejemplo 1:
 * 	Entrada:
 * 		nombres = ["Mirna", "Luis", "Moises", "Fernanda"]
 * 		objetivo = "Luis"
 * 	Salida:
 * 		1
 * Ejemplo 2:
 * 	Entrada:
 * 		nombres = ["Mirna", "Luis", "Moises", "Fernanda"]
 * 		objetivo = "María"
 * 	Salida:
 * 		-1
 * Ejemplo 3:
 * 	Entrada:
 * 		nombres = ["Mirna", "Luis", "Moises", "Fernanda"]
 * 		objetivo = "Fernanda"
 * 	Salida:
 * 		3
 */

#include <stdio.h>
#include <string.h>
#define STR_SIZE 100
#define LIST_SIZE 4

void ReadNames(char list[][STR_SIZE], char target[], int lsize);
int SearchList(char list[][STR_SIZE], char target[], int lsize);

int main()
{
	char name_list[LIST_SIZE][STR_SIZE];
	char target_name[STR_SIZE];

	ReadNames(name_list, target_name, LIST_SIZE);

	int index = SearchList(name_list, target_name, LIST_SIZE);

	if(index >= 0)
		printf("The name '%s' is on the list on index [%d]\n", target_name, index);
	else
		printf("The name '%s' is not on the list\n", target_name);
}

void ReadNames(char list[][STR_SIZE], char target[], int lsize)
{
	for(int i = 0; i < lsize; i++)
	{
		printf("name[%d]: ", i);
		scanf("%s", list[i]);
	}
	printf("Search for: ");
	scanf("%s", target);

}

int SearchList(char list[][STR_SIZE], char target[], int lsize)
{
	for(int i = 0; i < lsize; i++)
		if(!strcmp(list[i], target))
			return i;
	return -1;
}
