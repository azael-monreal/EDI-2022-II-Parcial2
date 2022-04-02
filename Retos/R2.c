/*
 * Conversión decimal a hexadecimal
 *
 *  Dado un número decimal construya una función que convierta dicho número en
 * una cadena que represente el valor del número en hexadecimal (base 16).
 */

#include <stdio.h>
#include <string.h>

char* convertHex(int dec, int p, char* h);

int main()
{
	unsigned int num;
	char hex[8] = "";

	printf("Number to convert: ");
	scanf("%u", &num);

	strcpy(hex, convertHex(num, 0, hex));

	printf("%u(DEC) = ", num);
	printf("%s(HEX)", hex);
}

char* convertHex(int dec, int p, char* h)
{
	if (dec > 0)
	{
		h[p] = ((dec % 16) + ((dec % 16 < 10) ? 48 : 55));
		convertHex(dec / 16, ++p, h);
	}

	for (int i = 0, j = strlen(h) - 1; i < j; i++, j--)
	{
		char temp = h[i];
		h[i] = h[j];
		h[j] = temp;
	}

	return h;
}
