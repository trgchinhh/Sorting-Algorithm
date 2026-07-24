#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "lib//header.h"

void selection_sort(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

#endif