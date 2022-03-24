/*
 * Encontrar la letra mas pequeña mayor que la que la de entrada
 *
 * Escriba un programa que dado un arreglo de caracteres letras que están
 * ordenadas en orden ascedente y un caracter objetivo, que te regrese el
 * caracter mas pequeño en el arreglo que sea mayor que el caracter objetivo.
 *
 * Considere a las letras circulares. Es decir si objetivo = 'z' y letras =
 * ['a', 'b'], la respuesta deberá ser 'a'.
 *
 * Ejemplo 1:
 * 	Entrada:  letras = ['c', 'f', 'j'], objetivo = 'a'
 * 	Salida:  'c'
 *
 * Ejemplo 2:
 * 	Entrada:  letras = ['c', 'f', 'j'], objetivo = 'c'
 * 	Salida:  'f'
 *
 * Ejemplo 3:
 * 	Entrada:  letras = ['c', 'f', 'j'], objetivo = 'd'
 * 	Salida:  'f'
 *
 * Consideraciones:
 * 	+ El arreglo de letras solo contendrá letras minúsculas del alfabeto en
 * inglés.
 * 	+ El arreglo letras estará ordenado en orden ascendente.
 * 	+ El arreglo contiene al menos dos caracteres diferentes.
 * 	+ El caracter objetivo es una letra minúscula del alfabeto en inglés
 */

#include <stdio.h>
#define SIZE 3

char SmallBigLetter(char letters[], int size, char target);

int main()
{
	char in[SIZE] = {'c', 'f', 'j'};
	char c;

	printf("Target char: ");
	scanf("%c", &c);

	printf("Smallest bigger char in the array: %c\n",
				 SmallBigLetter(in, SIZE, c));
}

char SmallBigLetter(char letters[], int size, char target)
{
	int min = 0, max = size - 1;

	while (min <= max)
	{
		int guess = (min + max) / 2;

		if (letters[guess] == target)
			return letters[(guess + 1) % size];

		else
		{
			if (letters[guess] < target)
				min = ++guess;
			else
				max = --guess;
		}
	}

	return letters[min % size];
}
