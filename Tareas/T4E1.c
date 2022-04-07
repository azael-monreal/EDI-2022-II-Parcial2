/*
 * Utilizando estructuras modele la información de fechas.  La estructura debe
 * permitir almacenar la información de: a. día b. mes (utilice el nombre del
 * mes, no el número) c. año
 *
 * Cree funciones para:
 *
 * ○ Capturar una fecha solicitandola al usuario
 * ○ Imprimir la fecha en el formato:  DD/MMMM/AAAA. Utilizando los valores:
 * 		dia = 1
 * 		mes = abril
 * 		año = 2019
 *
 * La función deberá imprimir 01/Abril/2019.  Note que el mes está escrito con
 * mayúscula la primer letra
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define SSIZE 10

typedef struct Date
{
	unsigned int day;
	char month[SSIZE];
	unsigned int year;
} Date;

void inputDate(Date* d);
void displayDate(Date d);

int main()
{
	Date date;

	inputDate(&date);
	displayDate(date);
}

void inputDate(Date* d)
{
	/* char m[SSIZE]; */

	printf("day: ");
	scanf("%u", &d->day);

	printf("month: ");
	scanf("%s", &d->month);
	d->month[0] = toupper(d->month[0]);
	for (int i = 1; i < strlen(d->month); ++i)
		d->month[i] = tolower(d->month[i]);

	printf("year: ");
	scanf("%u", &d->year);
}

void displayDate(Date d)
{
	printf("date: %02d/%s/%04d", d.day, d.month, d.year);
}
