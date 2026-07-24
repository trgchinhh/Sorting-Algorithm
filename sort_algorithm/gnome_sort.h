#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "lib//header.h"

void gnome_sort(vector<int>& a) {
    int n = a.size();
    int index = 0;
    while (index < n) {
        if (index == 0){
            index++;
        }
        else if (a[index] >= a[index - 1]){
            index++;
        }
        else {
            swap(a[index], a[index - 1]);
            index--;
        }
    }
}

#endif