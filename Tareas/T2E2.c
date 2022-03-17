/*
 * Dado un arreglo ordenado de enteros diferentes y un valor objetivo,
 * regresa el indice del objetivo si se encuentra dentro del arreglo, si no,
 * regresa el indice donde debería estar si fuera agregado al arreglo en orden. 
 *
 * Ejemplo 1:
 * 	Entrada:  nums = [1, 3, 5, 6], objetivo = 5
 * 	Salida:  2
 *  									
 * Ejemplo 2:
 * 	Entrada:  nums = [1, 3, 5, 6], objetivo = 2
 * 	Salida:  1
 *  																	
 * Ejemplo 3:
 * 	Entrada:  letras = [1, 3, 5, 6], objetivo = 7
 * 	Salida:  4
 */

#include <stdio.h>
#define SIZE 4

int SearchIndex(int list[], int size, int target);

int main()
{
	int nums[SIZE] = {1, 3, 5, 6};
	int num;

	printf("Search for: ");
	scanf("%d", &num);

	printf("The number '%d' is or would be found on index [%d]\n", num, SearchIndex(nums, SIZE, num));
}

int SearchIndex(int list[], int size, int target)
{
	int min = 0, max = size-1;

	while(min <= max)
	{
		int guess = (min+max)/2;

		if(list[guess] == target)
			return guess;

		else
		{
			if(list[guess] < target)
				min = ++guess;
			else
				max = --guess;
		}
	}
	return min;
}
