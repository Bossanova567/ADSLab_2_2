#ifndef ADSLAB_2_1_HEAP_H
#define ADSLAB_2_1_HEAP_H

#include <iostream>
using namespace std;

void MaxHeapify(int* A, int i, int heap_size);
void BuildMaxHeap(int* A, int n);
void MinHeapify(int* A, int i, int heap_size);
void BuildMinHeap(int* A, int n);
void HeapSort(int* A, int n, int choice);
void Show(int* A, int heap_size);
int HeapMax(int* A);
int HeapExtractMax(int* A, int n);
void HeapIncreaseKey(int* A, int i, int key);
int MaxHeapInsert(int* A, int heap_size, int key);
int HeapMin(int* A);
int HeapExtractMin(int* A, int n);
void HeapDecreaseKey(int* A, int i, int key);
int MinHeapInsert(int* A, int heap_size, int key);

#endif //ADSLAB_2_1_HEAP_H
