#ifndef FLASH_SORT_H
#define FLASH_SORT_H

#include "lib//header.h"

void flash_sort(vector<int>& a) {
    int n = a.size();
    if (n <= 1){
        return;
    }
    int min_value = a[0];
    int max_value = a[0];
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min_value) min_value = a[i];
        if (a[i] > max_value) {
            max_value = a[i];
            max_index = i;
        }
    }
    if (min_value == max_value){
        return;        
    } 
    int m = int(0.45 * n);
    vector<int> L(m, 0);
    double c = double(m - 1) / (max_value - min_value);
    for (int x : a){
        L[int(c * (x - min_value))]++;
    }
    for (int i = 1; i < m; i++){
        L[i] += L[i - 1];
    }
    swap(a[max_index], a[0]);

    int move = 0;
    int j = 0;
    int k = m - 1;
    int flash;
    while (move < n - 1) {
        while (j > L[k] - 1) {
            j++;
            k = int(c * (a[j] - min_value));
        }
        flash = a[j];
        while (j != L[k]) {
            k = int(c * (flash - min_value));
            swap(flash, a[--L[k]]);
            move++;
        }
    }

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

#endif