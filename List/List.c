#include "Source.h"

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
	deleteelemlos(los, 0);
	printlos(los);
	LOS item = { 20, NULL };
	los = addelemtomiddle(los, item, 1);
	printlos(los);
	Change(los, 2, 6);
	printlos(los);
	deletlos(los);
	return 0;


}
void printlos(LOS* los) { // Вывод списка
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
	printf("\nСписок удалён");
}

LOS* Change(LOS* los, int i, int b) {
	LOS* min = los;
	LOS* max = los;
	LOS* _max = los;
	if (i != 0) {
		for (size_t n = 0; n < i - 1; n++)
		{
			min = min->next;
		}
		for (size_t n = 0; n < b - 1; n++)
		{
			_max = _max->next;
		}
		LOS* l2 = _max->next;
		max = l2->next;
		LOS* l1 = min->next;
		min->next = l2;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return los;
	}
	else {
		for (size_t n = 0; n < b - 1; n++)
		{
			_max = _max->next;
		}
		LOS* l2 = _max->next;
		max = l2->next;
		LOS* l1 = min->next;
		l2->next = l1;
		_max->next = min;
		min->next = max;
		return l2;
	}

}



