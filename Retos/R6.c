/*
 * Encuentra el ganador del juego circular
 *
 * Existen n amigos que están jugando un juego.  Los amigos están sentados en un
 * círculo y están numerados de 1 a n en el sentido de las manecillas del reloj.
 * Mas formalmente, moverse en las manecillas del reloj desde el i-esimo amigo
 * te llevara al amigo i+1, para 1 <= i < n, y moverse en el sentido de las
 * manecillas del reloj desde el n-esimo amigo te llevara al 1er amigo.
 *
 * Las reglas del juego son:
 * 1. Se inicia en el primer amigo
 * 2. Se cuenta k amigos en el sentido de las manecillas del reloj incluyendo
 * al amigo con el que iniciaste.  La cuenta continua sobre el circulo y puedes
 * contar algunos amigos más de una vez.
 * 3. El último amigo que cuentes deja el circulo y pierde el juego.
 * 4. Si existe más de un amigo en el círculo, regresas al paso 2 iniciando por
 * el amigo inmediato en el sentido de las manecillas del reloj del amigo que
 acaba
 * de perder y así en cada vez que pierda un amigo.
 * 5. Hasta que solo exista un amigo en el círculo, quien ganará el juego.
 *
 * Dado el número de amigos N, y un entero k, regresa el ganador del juego.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct QNode QNode;
typedef struct CQueue CQueue;

CQueue* createQueue();
int isEmpty(CQueue* q);
void enQueue(CQueue* q, int data);

void initiateCQueue(CQueue* q, int n);
int gameWinner(CQueue* q, int k);

int main()
{
	CQueue* friends = createQueue();

	int n, k;

	printf("n: ");
	scanf("%d", &n);
	initiateCQueue(friends, n);
	printf("k: ");
	scanf("%d", &k);

	printf("%d\n", gameWinner(friends, k));
}

struct QNode
{
	int data;
	struct QNode* next;
};

struct CQueue
{
	QNode *front, *rear;
};

CQueue* createQueue()
{
	CQueue* q = (CQueue*)malloc(sizeof(CQueue));
	q->front = q->rear = NULL;

	return q;
}

int isEmpty(CQueue* q) { return !q->front; }

void enQueue(CQueue* q, int data)
{
	QNode* qNode = (QNode*)malloc(sizeof(QNode));

	qNode->data = data;

	if (isEmpty(q))
		q->front = qNode;
	else
		q->rear->next = qNode;

	q->rear = qNode;
	q->rear->next = q->front;
}

void initiateCQueue(CQueue* q, int n)
{
	for (int i = 0; i < n; i++)
		enQueue(q, i + 1);
}

int gameWinner(CQueue* q, int k)
{
	if (isEmpty(q))
		return 0;

	QNode* node = q->front;

	while (node != node->next)
	{
		for (int i = 0; i < k - 2; i++)
			node = node->next;
		QNode* temp = node->next;

		node->next = temp->next;
		free(temp);
		node = node->next;
	}

	return node->data;
}
