#include <stdio.h>
#include <malloc.h>

struct list {
	int a;
	struct lust* next;
};
typedef struct list* LOS;

LOS* initLOS(int);
void printlos(LOS);


LOS* initLOS(int n) {
	LOS los = malloc(1,sizeof(LOS));
	los->a = 1;
	LOS p1 = los, p2;
	for (int i = 0; i < n-1; i++) {
		p2 = malloc(1, sizeof(LOS));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;
	}
	p1->next = NULL;
	return los;
}

int main()
{
	LOS los = initLOS(10);
	printlos(los);


}
void printlos(LOS los) {
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
}

