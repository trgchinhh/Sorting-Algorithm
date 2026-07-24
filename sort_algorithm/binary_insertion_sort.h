#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "lib//header.h"

int binary_search(vector<int>& a, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= key){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return left;
}

void binary_insertion_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int pos = binary_search(a, 0, i - 1, key);
        for (int j = i - 1; j >= pos; j--)
            a[j + 1] = a[j];
        a[pos] = key;
    }
}

#endif