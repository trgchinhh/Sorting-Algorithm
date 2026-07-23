#ifndef INTRO_SORT_HPP
#define INTRO_SORT_HPP

#include "lib//header.hpp"

void intro_insertion_sort(vector<int>& a, int left, int right) {
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

void intro_heap(vector<int>& a, int n, int i, int offset) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[offset + l] > a[offset + largest]){
        largest = l;
    }
    if (r < n && a[offset + r] > a[offset + largest]){
        largest = r;
    }
    if (largest != i) {
        swap(a[offset + i], a[offset + largest]);
        intro_heap(a, n, largest, offset);
    }
}

void intro_heap_sort(vector<int>& a, int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; i--){
        intro_heap(a, n, i, left);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[left], a[left + i]);
        intro_heap(a, i, 0, left);
    }
}

int intro_partition(vector<int>& a, int left, int right) {
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}

void intro_sort_impl(vector<int>& a, int left, int right, int depth_limit) {
    while (right - left > 16) {
        if (depth_limit == 0) {
            intro_heap_sort(a, left, right);
            return;
        }
        depth_limit--;
        int p = intro_partition(a, left, right);
        intro_sort_impl(a, p + 1, right, depth_limit);
        right = p - 1;
    }
    if (left < right){
        intro_insertion_sort(a, left, right);
    }
}

void intro_sort(vector<int>& a) {
    if (a.empty()){
        return;
    }
    int depth = 2 * log2(a.size());
    intro_sort_impl(a, 0, a.size() - 1, depth);
}

#endif