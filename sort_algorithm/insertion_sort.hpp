#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "lib//header.hpp"

void insertion_sort(vector<int>& a){
    int n = a.size();
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }   
}

#endif