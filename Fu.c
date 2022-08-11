#include "Heap.h"

void test1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 15,18,19,25,34,65,49,27,27 };
	for (int i = 0; i < 9; i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
}

void test2()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 15,18,19,25,34,65,49,27,27 };
	for (int i = 0; i < 9; i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
}

void test3()
{
	const char* filename = "data.txt";
	int k = 5;
	PrintTopK(filename, k);
}

void test4()
{
	const char* filename = "data.txt";
	int N = 10000;
	int k = 10;
	CreateDataFile(filename, N);
	//PrintTopK(filename, k);
}

int main()
{
	//test1();
	test2();
	//test3();
	//test4();

	return 0;

}