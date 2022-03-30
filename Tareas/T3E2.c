/*
 * Dado un arreglo de enteros num, de tamaño n, realice una función que devuelva
 * el elemento que aparezca mas veces dentro del arreglo.
 *
 * Ejemplo 1:
 *
 * 	Entrada:  nums = [3, 2, 3]
 * 	Salida:  3
 * 	Explicación:  El 3 aparece dos veces dentro del arreglo y el 2 solo una vez.
 *
 * Ejemplo 2:
 *
 * 	Entrada:  nums = [2, 2, 1, 1, 1, 2, 2]
 * 	Salida:  2
 * 	Explicación:  El 2 aparece mas veces que el 1.
 *
 * Ejemplo 3:
 *
 * 	Entrada:  nums = [1, 3, 1, 4, 3, 2, 1, 3, 2, 1]
 * 	Salida:  1
 * 	Explicación:  El 1 parece mas veces que todos los demás dentro del arreglo.
 *
 */

#include <stdio.h>
#define SIZE 100

void ReadArray(int arr[], int* size, char name[]);
int MostRepeated(int arr[], int size);
void quickSort(int arr[], int l, int h);

int main()
{
	int nums[SIZE], n;
	ReadArray(nums, &n, "nums");
	quickSort(nums, 0, n - 1);
	printf("%d", MostRepeated(nums, n));
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

int MostRepeated(int arr[], int size)
{
	int index, high = -1;
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];
		int rep = 0;
		while (temp == arr[i + 1])
		{
			rep++;
			i++;
		}
		if (high < rep)
		{
			index = i;
			high = rep;
		}
	}
	return arr[index];
}
