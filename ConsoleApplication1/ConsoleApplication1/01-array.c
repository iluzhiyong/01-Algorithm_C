
#include <stdio.h>
#include "01-array.h"

#define ARRAY_NUM	10

typedef struct
{
	int dwArray[ARRAY_NUM];
	int dwSize;
} T_Array;

static T_Array s_TArray = { 0 };

int array_insert(int element, int index)
{
	if (index > s_TArray.dwSize || index < 0)
		return -1;

	for (int i = (s_TArray.dwSize - 1); i >= index; i--)
	{
		s_TArray.dwArray[i + 1] = s_TArray.dwArray[i];
	}

	s_TArray.dwArray[index] = element;
	s_TArray.dwSize++;

	return 0;
}

int array_delete(int index)
{
	if (index < 0 || index >= s_TArray.dwSize)
		return -1;

	int deletedElement = s_TArray.dwArray[index];

	for (int i = index; i < s_TArray.dwSize - 1; i++)
		s_TArray.dwArray[i] = s_TArray.dwArray[i + 1];

	s_TArray.dwSize--;

	return deletedElement;
}

int array_output(void)
{
	for (int i = 0; i < s_TArray.dwSize; i++)
		printf("Array[%d]: %d\n\r", i, s_TArray.dwArray[i]);

	return 0;
}

int array_test(void)
{
	array_insert(3, 0);
	array_insert(7, 1);
	array_insert(9, 2);
	array_insert(5, 3);
	array_insert(6, 1);

	array_output();

	return 0;
}