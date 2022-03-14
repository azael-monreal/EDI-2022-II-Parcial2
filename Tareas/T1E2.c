/*
 * Realice un program que lea un número n y calucle en un afunción recursiva el fibonacci de n
 */

#include <stdio.h>

int Fibonacci(int n);

int main()
{
	int in;
	printf("Term in the series: ");
	scanf("%d", &in);
	printf("Term %d in the fibonacci series is %d", in, Fibonacci(in));
}

int Fibonacci(int n)
{
	if(n <= 1)
		return n;
	return Fibonacci(n-1)+Fibonacci(n-2);
}
