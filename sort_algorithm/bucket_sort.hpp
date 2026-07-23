#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP

#include "lib//header.hpp"

void bucket_sort(vector<int>& a) {
    if (a.empty()){
        return;
    }
    int min_value = *min_element(a.begin(), a.end());
    int max_value = *max_element(a.begin(), a.end());
    int bucket_count = a.size();
    vector<vector<int>> buckets(bucket_count);
    double range = double(max_value - min_value + 1) / bucket_count;
    for (int x : a) {
        int index = (x - min_value) / range;
        if (index >= bucket_count){
            index = bucket_count - 1;
        }
        buckets[index].push_back(x);
    }
    int idx = 0;
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        for (int x : bucket){
            a[idx++] = x;
        }
    }
}

#endif