#include "Heap.h"

// i - індекс елемента піраміди

int Parent(int i){
    return floor((i-1)/2);
}

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int* A, int i, int heap_size){
    int l = Left(i);
    int r = Right(i);
    int largest;
    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= heap_size && A[r] > A[largest])
        largest = r;
    if (largest != i){
        swap(A[i], A[largest]);
        MaxHeapify(A, largest, heap_size);
    }
}

void BuildMaxHeap(int* A, int n){
    for (int i = n/2-1; i >= 0; i--){
        MaxHeapify(A, i, n);
    }
}

void MinHeapify(int* A, int i, int heap_size){
    int l = Left(i);
    int r = Right(i);
    int smallest;
    if (l <= heap_size && A[l] < A[i])
        smallest = l;
    else
        smallest = i;
    if (r <= heap_size && A[r] < A[smallest])
        smallest = r;
    if (smallest != i){
        swap(A[i], A[smallest]);
        MinHeapify(A, smallest, heap_size);
    }
}

void BuildMinHeap(int* A, int n){
    for (int i = n/2-1; i >= 0; i--){
        MinHeapify(A, i, n);
    }
}

void HeapSort(int* A, int n, int choice){
    if (choice == 1) {
        BuildMaxHeap(A, n);
        for (int i = n - 1; i > 0; i--) {
            swap(A[0], A[i]);
            MaxHeapify(A, 0, i);
        }
    }
    if (choice == 2){
        BuildMinHeap(A, n);
        for (int i = n - 1; i > 0; i--) {
            swap(A[0], A[i]);
            MinHeapify(A, 0, i);
        }
    }
}

void Show(int* A, int heap_size){
    for (int i = 0; i <= heap_size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int HeapMax(int* A){
    return A[0];
}

int HeapExtractMax(int* A, int heap_size){
    if (heap_size < 0) {
        cout << "Error. The queue is empty" << endl;
        return heap_size;
    }
    else {
        int max = A[0];
        A[0] = A[heap_size];
        heap_size -= 1;
        MaxHeapify(A, 0, heap_size);
        return heap_size;
    }
}

void HeapIncreaseKey(int* A, int i, int key){
    if (key < A[i]){
        cout << "The new key is smaller than current one" << endl;
    }
    else{
        A[i] = key;
        while (i > 0 && A[Parent(i)] < A[i]){
            swap(A[i], A[Parent(i)]);
            i = Parent(i);
        }
    }
}

int MaxHeapInsert(int* A, int heap_size, int key){
    heap_size += 1;
    A[heap_size] = INT_MIN;
    HeapIncreaseKey(A, heap_size, key);
    return heap_size;
}

int HeapMin(int* A){
    return A[0];
}

int HeapExtractMin(int* A, int heap_size){
    if (heap_size < 0) {
        cout << "Error. The queue is empty" << endl;
        return heap_size;
    }
    else {
        int min = A[0];
        A[0] = A[heap_size];
        heap_size -= 1;
        MinHeapify(A, 0, heap_size);
        return heap_size;
    }
}

void HeapDecreaseKey(int* A, int i, int key){
    if (key > A[i]){
        cout << "The new key is larger than current one" << endl;
    }
    else{
        A[i] = key;
        while (i > 0 && A[Parent(i)] > A[i]){
            swap(A[i], A[Parent(i)]);
            i = Parent(i);
        }
    }
}

int MinHeapInsert(int* A, int heap_size, int key){
    heap_size += 1;
    A[heap_size] = INT_MAX;
    HeapDecreaseKey(A, heap_size, key);
    return heap_size;
}