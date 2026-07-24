#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "lib//header.h"

void radix_counting_sort(vector<int>& a, int exp){
    int n = a.size();
    vector<int> output(n);
    vector<int> cnt(10, 0);
    for(int x : a){
        cnt[(x / exp) % 10]++;
    }
    for(int i = 1; i < 10; i++){
        cnt[i] += cnt[i-1];
    }
    for(int i = n - 1; i >= 0; i--){
        int digit = (a[i] / exp) % 10;
        output[cnt[digit] - 1] = a[i];
        cnt[digit]--;
    }
    a = output;
}

void radix_sort(vector<int>& a){
    int max_value = *max_element(a.begin(), a.end());
    for(int exp = 1; max_value / exp > 0; exp *= 10){
        radix_counting_sort(a, exp);
    }
}

#endif 