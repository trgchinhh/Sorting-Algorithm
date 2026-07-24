#ifndef TIM_SORT_H
#define TIM_SORT_H

#include "lib//header.h"

void tim_insertion_sort(vector<int>& a, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= left && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void tim_merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]){
            a[k++] = left[i++];
        } else{
            a[k++] = right[j++];
        }
    }
    while (i < left.size()){
        a[k++] = left[i++];
    }
    while (j < right.size()){
        a[k++] = right[j++];
    }
}

void tim_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i += RUN){
        tim_insertion_sort(a, i, min(i + RUN - 1, n - 1));
    }
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            if (mid < right){
                tim_merge(a, left, mid, right);
            }
        }
    }
}

#endif