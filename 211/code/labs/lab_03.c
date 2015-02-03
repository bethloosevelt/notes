#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct arrElemStruct
{
 double value1;
 int value2;
 int value3;
} arrElem;


void init1(arrElem el)
{
  el.value1 = (double)(rand()) * rand() / rand();
  el.value2 = rand() % 100;
  el.value3 = rand() % 1000;
  printf ("In init1(): value1: %14.5f, value2: %6d, value3: %6d\n",
           el.value1, el.value2, el.value3);
}

void init2(arrElem* el)
{
  el->value1 = (double)(rand()) * rand() / rand();
  el->value2 = rand() % 100;
  el->value3 = rand() % 1000;
  printf ("In init2(): value1: %14.5f, value2: %6d, value3: %6d\n",
           el->value1, el->value2, el->value3);
}


int main (int argc, char**argv)
{
  /* All three variables a1, a2, and a3 are intended to be used as *
   * some form of array of the struct type declared above.         */
  arrElem a1[SIZE]; 
  arrElem* a2[SIZE];
  arrElem* a3;
  int i;

  printf ("Calling init1()\n");
  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     init1 (a1[i]);                     /* FIRST CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a1[i].value1, a1[i].value2, a1[i].value3);
    }

  printf ("\nRepeating with init2()\n");
  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     init2 (&(a1[i]));                 /* SECOND CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a1[i].value1, a1[i].value2, a1[i].value3);
    }


  printf ("\nRepeating call to init2() with a2\n");

  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     init2 (a2[i]);                  /* THIRD CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a2[i]->value1, a2[i]->value2, a2[i]->value3);
    }

  printf ("\nRepeating call to init2() with a3\n");

  for (i = 0 ; i < SIZE; ++i)
    {
     printf ("For position %d\n", i);
     init2 (&(a3[i]));                  /* FOURTH CALL */
     printf ("In main(): value1: %14.5f, value2: %6d, value3: %6d\n",
             a3[i].value1, a3[i].value2, a3[i].value3);
    }


}


