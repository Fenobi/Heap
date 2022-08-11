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

//���ϵ�������
void AdjustUp(HPDataType* a, int child);

//���µ�������
void AdjustDown(HPDataType* a, int n, int parent);

//��ӡ
void HeapPrint(HP * php);

//�Ѷ���
void HeapInit(HP* php);

//������
void HeapDestroy(HP* php);

// ����x�����������̬
void HeapPush(HP* php, HPDataType x);

// ɾ���Ѷ�Ԫ�� -- �Ҵδ���ߴ�С
void HeapPop(HP* php);

// ���ضѶ���Ԫ��
HPDataType HeapTop(HP* php);

bool HeapEmpty(HP* php);

int HeapSize(HP* php);

//������
void HeapSort(HPDataType* a, int n);

//TopK����
void PrintTopK(const char* filename, int k);

//д�ļ�
void CreateDataFile(const char* filename,int N);
