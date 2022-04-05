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
#include <stdlib.h>

#define M 100
#define N 100
#define MN 200

void PrintArray(int arr[], int size, char name[]);
void ReadArray(int arr[], int* size, char name[]);

void merge(int a[], int s1, int b[], int s2, int out[]);

int main()
{
	int nums1[M], nums2[N], combined[MN];
	int m, n, mn;

	ReadArray(nums1, &m, "numbers1");
	PrintArray(nums1, m, "numbers1");

	ReadArray(nums2, &n, "numbers2");
	PrintArray(nums2, n, "numbers2");

	mn = m + n;

	merge(nums1, m, nums2, n, combined);

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

void merge(int a[], int s1, int b[], int s2, int out[])
{
	int i, j, k;

	for (i = j = k = 0; i < s1 && j < s2; k++)
	{
		if (a[i] <= b[j])
		{
			out[k] = a[i];
			i++;
		}
		else
		{
			out[k] = b[j];
			j++;
		}
	}

	for (; i < s1; i++, k++)
		out[k] = a[i];
	for (; j < s2; j++, k++)
		out[k] = b[j];
}
