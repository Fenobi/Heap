#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}


void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	php->capacity = php->size = 0;
	php->a = NULL;
	free(php);
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}

void HeapPop(HP* php)
{
	assert(php);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);

}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	return php->a;
}

int HeapSize(HP* php)
{
	return php->size;
}

void HeapSort(HPDataType* a, int n)
{
	//大思路：选择排序，依次选数，从后往前排
	//升序 -- 大堆 | 降序 -- 小堆
	//建堆 -- 向下调整建堆 - O(N)
	//第一个和最后位置交换，把最后一个不看做堆里面的
	//向下调整，选出次大的，后续依次类似处理。
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//选数
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		i++;
	}
}

void PrintTopK(const char* filename, int k)
{
	assert(filename);

	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("minHeap fail");
		return;
	}
	//读取数据
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	//建堆
	//建k个数小堆
	for (int j = (k - 1 - 1) / 2; j >= 0; j--)
	{
		AdjustDown(minHeap, k, j);
	}
	//继续读取后N-K
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	free(minHeap);
	fclose(fout);
}

void CreateDataFile(const char* filename, int N)
{
	assert(filename);

	FILE* fin = fopen(filename, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		fprintf(fin, "%d\n", rand());
	}

	fclose(fin);
}
