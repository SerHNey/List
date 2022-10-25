#pragma once
#include <stdio.h>
#include <malloc.h>


typedef struct LOS {
	int a;
	struct LOS* next;
}LOS;

LOS* initLOS(int);
void printlos(LOS*);
void deleteelemlos(LOS* los, int a);
void deletlos(LOS* los);
LOS* addelemtomiddle(LOS* los, LOS elem, int a);
LOS* Change(LOS* los, int i, int b);