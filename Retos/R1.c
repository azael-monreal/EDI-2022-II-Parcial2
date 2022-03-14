/*
 * Producto del arreglo excepto el mismo
 *
 * Dado un arreglo de enteros nums, realice una función que regrese un arreglo respuesta en el cual cada elemento respuesta[i]
 * deberá ser igual al producto de todos los elementos de nums excepto nums[i].
 *
 * Ejemplo 1:
 * 	Entrada:  nums = [1, 2, 3, 4]
 * 	Salida:  [24, 12, 8, 6]
 *
 * Ejemplo 2:
 * 	Entrada:  nums = [-1, 1, 0, -3, 3]
 * 	Salida:  [0, 0, 9, 0, 0]
 *
 * Restricciones:
 * 	-30 <= nums[i] <= 30
 */

#include <stdio.h>
#define SIZE 5

void Multiply(int in[], int out[]);

int main()
{
	int nums[SIZE];
	int results[SIZE];

	printf("*** Array values ***\n");
	for(int i=0; i<SIZE; i++)
	{
		printf("[%d]: ", i);
		scanf("%d", &nums[i]);
	}

	Multiply(nums, results);

	printf("*** Result ***\n[ ");
	for(int i=0; i<SIZE; i++)
		printf("%d ", results[i]);
	printf("]");
}

void Multiply(int in[], int out[])
{
	for(int i = 0; i<SIZE; i++)
	{
		int prod = 1;
		for(int j = 0; j<SIZE; j++)
		{
			if(j==i)
				continue;
			prod*=in[j];
		}
		out[i] = prod;
	}
}
