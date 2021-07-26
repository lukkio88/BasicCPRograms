#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*
* Controlla se v[i] e' un singleton (cioe non ha duplicati)
* Return:
*   TRUE se non ha duplicati
*   FALSE se ha duplicati
*/
int isSingleton(int v[], int size, int i)
{
	for (int j = 0; j < size; ++j)
	{
		if (i != j)
		{
			if (v[i] == v[j])
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

/*
* Controlla se "el" e' nell'array v
* RETURN:
*   TRUE se "el" e' nell'array
*   FALSE se "el" non e' nell'array
*/
int isInArray(int v[], int size, int el)
{
	for (int i = 0; i < size; ++i)
	{
		if (el == v[i])
		{
			return TRUE;
		}
	}
	return FALSE;
}

/*
* Calcola tutti gli elementi che non hanno duplicati nell'array v
* RETURN:
*   numero di elementi senza duplicati
*/
int findSingletons(int v[], int marked[], int singleton[], int size)
{

	int kMarked = 0;
	int kSingleton = 0;

	for (int i = 0; i < size; ++i) //Setaccio tutti gli elementi dell'input array
	{
		if (isInArray(marked, kMarked, v[i])) //Controlla se un elemento = v[i] l'ho gia controllato
		{
			continue; //Se gia controllato, non faccio nulla, continuo alla prossima iterazione
		}
		else
		{
			marked[kMarked] = v[i]; //Se non l'ho mai controllato lo aggiungo ai marcati
			++kMarked;
		}
		if (isSingleton(v, size, i)) //Controllo se questo elemento non ha duplicati
		{
			singleton[kSingleton] = v[i]; //Se non ha duplicati lo aggiungo ai duplicati
			++kSingleton;
		}
	}
	return kSingleton;
}

#define MAX_SIZE 100

int main()
{

	int inputArray[MAX_SIZE];
	int marked[MAX_SIZE];
	int singleton[MAX_SIZE];

	printf("Insert the array size ");
	int sizeArray;
	scanf("%d", &sizeArray);
	for (int i = 0; i < sizeArray; ++i)
	{
		printf("Insert element[%d] = ", i);
		scanf("%d", &inputArray[i]);
	}

	printf("inputArray = {");
	for (int i = 0; i < sizeArray; ++i)
	{
		printf("%d ", inputArray[i]);
	}
	printf("};\n");

	int numberOfSingleton = findSingletons(inputArray, marked, singleton, sizeArray);

	if (numberOfSingleton == 0)
	{
		printf("There're no singletons");
	}
	else
	{
		printf("Singletons are: {");
		for (int i = 0; i < numberOfSingleton; ++i)
		{
			printf("%d ", singleton[i]);
		}
		printf("};\n");
	}
}