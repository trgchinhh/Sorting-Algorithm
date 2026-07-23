#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "lib//header.hpp"

void bubble_sort(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }   
}

#endif