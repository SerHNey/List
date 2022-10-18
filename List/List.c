#include <stdio.h>
#include <malloc.h>


typedef struct LOS {
	int a;
	struct LOS* next;
}LOS;

LOS* initLOS(int);
void printlos(LOS*);
void addelemtoend(LOS* los, int a);
void deleteelemlos(LOS* los, int a);
void deletlos(LOS* los);
LOS* addelemtomiddle(LOS* los, LOS elem, int a);

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
	addelemtoend(los, 10);
	printlos(los);
	deleteelemlos(los, 5);
	printlos(los);
	LOS item = { 20, NULL };
	los = addelemtomiddle(los, item, 1);
	printlos(los);
	deletlos(los);
	return 0;


}
void printlos(LOS* los) {
	printf("\n");
	printf("Список: ");
	if (los == NULL) {
		printf("Список удалён");
		return;
	}
	
		while (los != NULL)
		{
			printf("%d ", los->a);
			los = los->next;
		}
		
	
	printf("\n");
}

void addelemtoend(LOS* los, int a) {
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

LOS* addelemtomiddle(LOS* los,  LOS elem, int a) {
	LOS* element = malloc(sizeof(LOS));
	element->a = elem.a;

	if (a == 1) {
		element->next = los;
		los = element;
	}
	else
	{
		 for (size_t i = 1; i < a-1; i++)
		{
			los = los->next;
			if (!(los->next)) {
			break;
			}
		}

		void* temp = los->next;
		los->next = element;
		element->next = temp;
	}
	return los;
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
	LOS* los1 = los;
	while (los1)
	{
		los1 = los->next;
		free(los);
		los = los1;
	}
	printf("\nСписок удалён1");
}

LOS* Change(LOS* los, int a, int b) {


}



