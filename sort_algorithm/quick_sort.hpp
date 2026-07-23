#ifndef QUICKSORT_SORT_HPP
#define QUICKSORT_SORT_HPP

#include "lib//header.hpp"

int partition(vector<int>& a, int left, int right){
    int pivot = a[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[right]);
    return i + 1;
}

void quick_sort(vector<int>& a, int left, int right){
    if(left < right){
        int pivot = partition(a, left, right);
        quick_sort(a, left, pivot - 1);
        quick_sort(a, pivot + 1, right);
    }
}

#endif