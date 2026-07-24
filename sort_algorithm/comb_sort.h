#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "lib//header.h"

void comb_sort(vector<int>& a) {
    int n = a.size();
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

#endif