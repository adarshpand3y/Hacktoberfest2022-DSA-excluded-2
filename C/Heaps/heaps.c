#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heaps.h"

void perculateDown(Heaps *h, int pos);

Heaps *_Init_Heap(size_t Max_size, int (*cmp)(HeapElement a, HeapElement b))
{
    Heaps *temp = (Heaps *)malloc(sizeof(Heaps));
    assert(temp != NULL);
    temp->max_size = Max_size;
    temp->comparator_funct = cmp;
    temp->curr_size = 0;
    temp->Arr = (HeapElement *)malloc((Max_size + 1) * sizeof(HeapElement));
    return temp;
}

void insertIntoHeap(Heaps *h, HeapElement _t)
{
    h->Arr[++h->curr_size] = _t;
    int iter = h->curr_size;
    while (iter > 1 && (*(h->comparator_funct))(h->Arr[iter], h->Arr[iter / 2]))
    {
        h->Arr[iter] = h->Arr[iter] + h->Arr[iter / 2] - (h->Arr[iter / 2] = h->Arr[iter]);
        HeapElement temp = h->Arr[iter];
        h->Arr[iter] = h->Arr[iter / 2];
        h->Arr[iter / 2] = temp;
        iter /= 2;
    }
}

HeapElement GetMinHeap(Heaps *h)
{
    return h->Arr[1];
}

Heaps *buildHeap(size_t _n, HeapElement arr[], int (*cmp)(HeapElement a, HeapElement b))
{
    Heaps *h = _Init_Heap(_n, cmp);
    for (int i = 0; i < _n; i++)
    {
        h->Arr[i + 1] = arr[i];
    }
    h->curr_size = _n;
    for (int i = _n / 2; i > 0; i--)
    {
        perculateDown(h, i);
    }
    return h;
}

HeapElement removeMinFromHeap(Heaps *h)
{
    HeapElement temp = h->Arr[1];
    h->Arr[1] = h->Arr[h->curr_size];
    h->curr_size--;
    perculateDown(h, 1);
    return temp;
}

void perculateDown(Heaps *h, int pos)
{
    int iter = pos;
    while (iter < h->curr_size)
    {
        if (2 * iter > h->curr_size)
        {
            return;
        }
        else if (2 * iter + 1 > h->curr_size)
        {
            if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]))
            {
                HeapElement temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter];
                h->Arr[2 * iter] = temp;
            }
            return;
        }
        else
        {
            if ((*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                return;
            }
            else if ((*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter]) && (*(h->comparator_funct))(h->Arr[2 * iter + 1], h->Arr[iter]))
            {
                HeapElement temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter + 1];
                h->Arr[2 * iter + 1] = temp;
                iter = 2 * iter + 1;
            }
            else if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                HeapElement temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter];
                h->Arr[2 * iter] = temp;
                iter = 2 * iter;
            }
            else
            {
                if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[2 * iter + 1]))
                {

                    HeapElement temp = h->Arr[iter];
                    h->Arr[iter] = h->Arr[2 * iter];
                    h->Arr[2 * iter] = temp;
                    iter = 2 * iter;
                }
                else
                {
                    HeapElement temp = h->Arr[iter];
                    h->Arr[iter] = h->Arr[2 * iter + 1];
                    h->Arr[2 * iter + 1] = temp;
                    iter = 2 * iter + 1;
                }
            }
        }
    }
}