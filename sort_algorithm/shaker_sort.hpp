#ifndef SHAKER_SORT_HPP
#define SHAKER_SORT_HPP

#include "lib//header.hpp"

void shaker_sort(vector<int>& a) {
    int left = 0;
    int right = a.size() - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        right--;
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1])
                swap(a[i], a[i - 1]);
        }
        left++;
    }
}

#endif