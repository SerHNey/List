#include <stdio.h>
#include <malloc.h>


typedef struct LOS {
	int a;
	char by;
	struct LOS* next;
}LOS;


LOS* initLOS(int);
void printlos(LOS*);
void addelem(LOS* los, int a);
void deleteelemlos(LOS* los, int a);
void deletlos(LOS* los);


LOS* initLOS(int n) {
	LOS* los = calloc(1,sizeof(LOS));

	LOS* p1 = los, *p2;
	for (int i = 0; i < n-1; i++) {
		p2 = calloc(1, sizeof(LOS));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;

	}
	p1->next = NULL;
	return los;
}


int main()
{
	system("chcp 1251 >null");
	LOS* los;
	los = initLOS(10);
	printlos(los);
	addelem(los, 10);
	printlos(los);
	deleteelemlos(los, 5);
	printlos(los);
	return 0;


}
void printlos(LOS* los) {
	printf("\n");
	printf("Список: ");
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
	printf("\n");
}

void addelem(LOS* los, int a) {
	int count = 1; // Количество элементов
	while (los->next != NULL)
	{
		los = los->next;
	}
	LOS* newelem = calloc(count, sizeof(LOS));
	newelem->a = a;
	newelem->next = NULL;
	los->next = newelem;
	
}

void deleteelemlos(LOS* los, int a) {
	a--;
	while (los->a != a)
	{

		los = los->next;
	}
	LOS* copy = los;
	los = los->next;
	copy->next = los->next;
	free(los);
}
void deletlos(LOS* los) {
	while (los->next != NULL)
	{

	}
}


