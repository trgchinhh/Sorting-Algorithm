#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "lib//header.h"

void heap(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]){
        largest = left;
    }
    if (right < n && a[right] > a[largest]){
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heap(a, n, largest);
    }
}

void heap_sort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--){
        heap(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

#endif