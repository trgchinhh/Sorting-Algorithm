#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "lib//header.h"

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