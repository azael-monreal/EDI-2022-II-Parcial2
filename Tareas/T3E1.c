/*
 * Dado un arreglo de enteros num, realice una función que regrese 1 si
 * cualquier valor dentro del arreglo aparece dos veces o mas en el arreglo  y
 * regrese 0 si cada elemento dentro del arreglo es distinto.
 *
 * Ejemplo 1:
 * 	Entrada:  nums = [1, 2, 3, 1]
 * 	Salida:  1
 * 	Explicación:  El 1 aparece dos veces dentro del arreglo.
 *
 * Ejemplo 2:
 * 	Entrada:  nums = [1, 4, 3, 2]
 * 	Salida:  0
 * 	Explicación:  Ningún valor se repite dentro del arreglo.
 *
 * Ejemplo 3:
 * 	Entrada:  nums = [1, 3, 1, 4, 3, 2, 1, 3, 2]
 * 	Salida:  1
 * 	Explicación:  Existen valores que aparecen mas de una vez (Nota:  no es
 * necesario saber que hay mas de uno que se repite).
 *
 */

#include <stdio.h>
#define SIZE 100

void ReadArray(int arr[], int* size, char name[]);
void quickSort(int arr[], int l, int h);
int CheckRepeats(int arr[], int size);

int main()
{
	int nums[SIZE], size;

	ReadArray(nums, &size, "nums");

	quickSort(nums, 0, size - 1);
	printf("%d", CheckRepeats(nums, size));
}

void ReadArray(int arr[], int* size, char name[])
{
	printf("%s[] size: ", name);
	scanf("%d", size);
	for (int i = 0; i < *size; i++)
	{
		printf("%s[%d]: ", name, i);
		scanf("%d", &arr[i]);
	}
}

void quickSort(int arr[], int l, int h)
{
	if (l >= h)
		return;

	int p = arr[h];
	int i = l - 1;

	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] < p)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[h];
	arr[h] = temp;

	int part = (i + 1);

	quickSort(arr, l, part - 1);
	quickSort(arr, part + 1, h);
}

int CheckRepeats(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] == arr[i + 1])
			return 1;
	return 0;
}
