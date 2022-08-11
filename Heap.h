#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//向上调整建堆
void AdjustUp(HPDataType* a, int child);

//向下调整建堆
void AdjustDown(HPDataType* a, int n, int parent);

//打印
void HeapPrint(HP * php);

//堆定义
void HeapInit(HP* php);

//堆销毁
void HeapDestroy(HP* php);

// 插入x继续报错堆形态
void HeapPush(HP* php, HPDataType x);

// 删除堆顶元素 -- 找次大或者次小
void HeapPop(HP* php);

// 返回堆顶的元素
HPDataType HeapTop(HP* php);

bool HeapEmpty(HP* php);

int HeapSize(HP* php);

//堆排序
void HeapSort(HPDataType* a, int n);

//TopK排序
void PrintTopK(const char* filename, int k);

//写文件
void CreateDataFile(const char* filename,int N);
