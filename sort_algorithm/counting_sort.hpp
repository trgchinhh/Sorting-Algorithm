#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include "lib//header.hpp"

void counting_sort(vector<int>& a, vector<int>& cnt){
    int idx = 0;
    for(int i = 0; i < cnt.size(); i++){
        while(cnt[i] > 0){
            a[idx] = i;
            cnt[i]--;
            idx++;
        }
    }
}

#endif