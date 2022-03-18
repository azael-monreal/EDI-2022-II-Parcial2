/*
 * Realice un programa que dada un cadena diga si es simétrica (palindroma)
 * 	a. Realice un afuncion recursiva que reciva la cadena y regrese un 1 si es palíndroma o un 0 si no.
 * 	b. Realice un afuncion que reciba la cadena y mediante ciclos regrese un 1 si la cadena es palindroma o un 0 si no.
 */

#include <stdio.h>
#include <string.h>
#define SIZE 100

int PalindromeRecursive(char string[], int size, int i, int j);
int PalindromeCycles(char string[], int size);


int main()
{
	char in[SIZE];
	printf("String: ");
	gets(in);

	printf("The string '%s' is%s a palindrome (recursive algorithm)\n", in, (PalindromeRecursive(in, strlen(in), 0, strlen(in)-1)) ? "":" not");
	printf("The string '%s' is%s a palindrome (cyclic algorithm)\n", in, (PalindromeCycles(in, strlen(in)) ? "":" not"));
}


int PalindromeRecursive(char string[], int size, int i, int j)
{
	if (string[i] == ' ')
		i++;
	if (string[j] == ' ')
		j--;
	if(i >= j)
		return 1;
	if(string[i] == string[j])
		return PalindromeRecursive(string, size, i+1, j-1);
	return 0;
}
int PalindromeCycles(char string[], int size)
{
	for(int i = 0, j = size-1; i < j; i++, j--)
	{
		while(string[i]==' ')
			i++;
		while(string[j]==' ')
			j--;
		if(string[i] != string[j])
			return 0;
	}
	return 1;
}
