/*
 * Utilizando estructuras modele la información de puntos en un plano
 * cartesiano.  Cada punto deberá contener x y y.  Realice las siguientes
 * funciones:
 * 		a. Capturar un punto solicitandolo al usuario.
 * 		b. Imprimir un punto con el siguiente formato (x, y)
 * 		c. Calcular la distancia entre dos puntos, la función recibirá dos puntos
 * como parámetro y regresará la distancia entre ellos.
 */

#include <math.h>
#include <stdio.h>

typedef struct Point
{
	float x, y;
} Point;

void inputPoint(Point* p, char* name);
void displayPoint(Point p, char* name);
float distanceBtwPoints(Point a, Point b);

int main()
{
	Point p1, p2;

	inputPoint(&p1, "p1");
	displayPoint(p1, "p1");
	inputPoint(&p2, "p2");
	displayPoint(p2, "p2");

	printf("distance: %f\n", distanceBtwPoints(p1, p2));
}

void inputPoint(Point* p, char* name)
{
	printf("%s.x: ", name);
	scanf("%f", &p->x);
	printf("%s.y: ", name);
	scanf("%f", &p->y);
}

void displayPoint(Point p, char* name)
{
	printf("%s: (%f, %f)\n", name, p.x, p.y);
}

float distanceBtwPoints(Point a, Point b)
{
	float d;
	d = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return d;
}
