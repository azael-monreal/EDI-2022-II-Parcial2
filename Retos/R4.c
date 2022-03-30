/*
 * Mezclar arreglos ordenados
 *
 * Dados dos arreglos de enteros, nums1 y num2, ordenados de forma ascendente y
 * dos enteros m y n que representan el número de elementos en nums1 y nums2
 * respectivamente.
 *
 * Mezcla nums1 y nums2 dentro de un arreglo simple ordenado de forma
 * ascendente.
 *
 * El arreglo final deberá ser un arreglo nuevo, cuya longitud será de m + n.
 *
 * Ejemplo 1:
 *
 * Entrada:  nums1 = [1, 2, 3], m = 3
 * nums2 = [2, 5, 6], n = 3
 * Salida:  [1, 2, 2, 3, 5, 6]
 *
 * Ejemplo 2:
 *
 * Entrada:  nums1 = [1], m = 1
 * nums2 = [], n = 0
 * Salida:  [1]
 *
 * Ejemplo 3:
 *
 * Entrada:  nums1 = [1, 6, 9, 12], m = 4
 * nums2 = [2, 5, 6], n = 3
 * Salida:  [1, 2, 5, 6, 6, 9, 12]
 *
 * Consideraciones:
 *
 * • m y n no serán mayores a 100
 * • m y n deberán ser solicitados al usuario
 */

#include <stdio.h>

#define M 100
#define N 100
#define MN 200

void PrintArray(int arr[], int size, char name[]);
void ReadArray(int arr[], int* size, char name[]);

void quickSort(int arr[], int l, int h);

int main()
{
	int numbs1[M], nums2[N], combined[MN];
	int m, n, mn;

	ReadArray(numbs1, &m, "numbers1");
	for (int i = 0; i < m; i++)
	{
		combined[i] = numbs1[i];
	}

	PrintArray(numbs1, m, "numbers1");

	ReadArray(nums2, &n, "numbers2");
	for (int i = 0; i < n; i++)
	{
		combined[m + i] = nums2[i];
	}

	PrintArray(nums2, n, "numbers2");

	mn = m + n;

	quickSort(combined, 0, mn - 1);

	PrintArray(combined, mn, "combined");
}

void PrintArray(int arr[], int size, char name[])
{
	printf("\n");
	printf("%s = [\t", name);
	for (int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("]\n\n");
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

void ReadArray(int arr[], int* size, char name[])
{
	printf("%s size: ", name);
	scanf("%d", size);
	for (int i = 0; i < *size; i++)
	{
		printf("%s[%d]: ", name, i);
		scanf("%d", &arr[i]);
	}
}
