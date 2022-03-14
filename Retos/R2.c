/*
 * Conversión decimal a hexadecimal
 *
 *  Dado un número decimal construya una función que convierta dicho número en una cadena que represente el valor del número en hexadecimal (base 16).
 */

#include <stdio.h>

void ConvertHex(int dec);

int main()
{
	int num;
	printf("Number to convert: ");
	scanf("%d", &num);

	printf("%d(DEC) = ", num);
	ConvertHex(num);
	printf("(HEX)");
}

void ConvertHex(int dec)
{
	if(dec>0)
	{
		ConvertHex(dec/16);
		printf("%c", (dec%16)+((dec%16<10)?48:55));
	}
}
