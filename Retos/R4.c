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
void ReadArray(int arr[], int *size, char name[]);

void Sort(int arr[], int l, int h);
int Partition(int arr[], int l, int h);
void Swap(int *a, int *b);

int main()
{
	int numbers1[M], numbers2[N], combined[MN];
	int m, n, mn;

	ReadArray(numbers1, &m, "numbers1");
	for (int i = 0; i < m; i++)
	{
		combined[i] = numbers1[i];
	}

	PrintArray(numbers1, m, "numbers1");

	ReadArray(numbers2, &n, "numbers2");
	for (int i = 0; i < n; i++)
	{
		combined[m + i] = numbers2[i];
	}

	PrintArray(numbers2, n, "numbers2");

	mn = m + n;

	Sort(combined, 0, mn - 1);

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

void Sort(int arr[], int l, int h)
{
	if (l < h)
	{
		int p = Partition(arr, l, h);

		Sort(arr, l, p - 1);
		Sort(arr, p + 1, h);
	}
}

int Partition(int arr[], int l, int h)
{
	int p = arr[h];
	int i = l - 1;

	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] < p)
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[h]);

	return (i + 1);
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void ReadArray(int arr[], int *size, char name[])
{
	printf("%s size: ", name);
	scanf("%d", size);
	for (int i = 0; i < *size; i++)
	{
		printf("%s[%d]: ", name, i);
		scanf("%d", &arr[i]);
	}
}
