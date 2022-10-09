#ifndef _HEAPS_HEADER_
#define _HEAPS_HEADER_
#include <stdio.h>

typedef int HeapElement;

typedef struct heaps{
    size_t curr_size;
    size_t max_size;
    HeapElement* Arr;   
    int (*comparator_funct)(HeapElement a,HeapElement b);
} Heaps;

Heaps* _Init_Heap(size_t Max_size,int (*cmp)(HeapElement a,HeapElement b));
void insertIntoHeap(Heaps* _h,HeapElement _t);
HeapElement GetMinHeap(Heaps* _h);
Heaps* buildHeap(size_t _n,HeapElement arr[],int (*cmp)(HeapElement a, HeapElement b));
HeapElement removeMinFromHeap(Heaps* _h);

#endif