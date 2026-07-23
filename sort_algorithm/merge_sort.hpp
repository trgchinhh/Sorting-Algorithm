#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "lib//header.hpp"

void merge(vector<int>& a, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]){
            temp.push_back(a[i++]);
        }
        else{
            temp.push_back(a[j++]);
        }
    }
    while (i <= mid){
        temp.push_back(a[i++]);
    }
    while (j <= right){
        temp.push_back(a[j++]);
    }
    for (int k = 0; k < temp.size(); k++){
        a[left + k] = temp[k];
    }
}

void merge_sort(vector<int>& a, int left, int right) {
    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}

#endif