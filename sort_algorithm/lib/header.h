#ifndef HEADER_SORT
#define HEADER_SORT

#include <cstdint>
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>
#include <conio.h>
#include "datetime.h"

using namespace dt;
using namespace std;

const int RUN = 32;
const int MAX_SIZE = 100000;
const int MAX_DISPLAY = 500;
int RANDOM_SIZE = 100;

const string BANNER = R"( ╔══════════════════════════════════╗
 ║        Sort Algorithm C++        ║
 ║  Some Sorting Algorithms C++     ║
 ║  Author : Truong Chinh           ║
 ║  Github : Github.com/trgchinhh   ║
 ╚══════════════════════════════════╝

)";

inline void pause_program(){
    cout << "\n Press enter to continue ..." << endl;
    getch();
}

inline void enter_random_size(int& RANDOM_SIZE, vector<int>& a, vector<int>& cnt){
    while(true){
        try {
        cout << " [?] Enter random size: ";
            if (!(cin >> RANDOM_SIZE)){
                throw invalid_argument(" [!] Please enter a number");
            }
            if(RANDOM_SIZE <= 0 || RANDOM_SIZE > MAX_SIZE){
                throw out_of_range(" [!] Size must be between 1 and " + to_string(MAX_SIZE));
            }
            a.resize(RANDOM_SIZE);
            cnt.assign(RANDOM_SIZE + 1, 0);
            break;
        }
        catch (const exception& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << e.what() << endl;
        }
    }
}

inline void print_banner(string banner){
    system("cls");
    stringstream ss(banner);
    string line;
    while (getline(ss, line)) {
        cout << line << endl;
    }
}

inline void print_menu() {
    vector<string> menuboard = {
        " [00] Enter random size",
        " [01] Bubble Sort",
        " [02] Selection Sort",
        " [03] Insertion Sort",
        " [04] Binary Insertion Sort",
        " [05] Shaker Sort",
        " [06] Shell Sort",
        " [07] Quick Sort",
        " [08] Merge Sort",
        " [09] Heap Sort",
        " [10] Counting Sort",
        " [11] Radix Sort",
        " [12] Bucket Sort",
        " [13] Flash Sort",
        " [14] Tim Sort",
        " [15] Intro Sort",
        " [16] Comb sort",
        " [17] Gnome sort",
        " [18] Tree sort",
        " [19] Exit Program"
    };
    for (string s : menuboard)
        cout << s << endl;
}

// tạo seed random trộn từ nhiều nguồn cho ra random ngẫu nhiên 
inline void c_srand(void){
    unsigned long long x, y, z;
    srand(static_cast<unsigned>(
        ::time(nullptr) 
        ^ clock() 
        ^ reinterpret_cast<uintptr_t>(&x)
        ^ (uintptr_t)&y
        ^ (uintptr_t)&z
    ));
}

inline datetime timenow(){
    return datetime::now();
}

inline auto print_timedelta(datetime start, datetime end) {
    long long diff = (end - start).total_milliseconds();
    if (diff < 1000) {
        cout << " Sort time: " << diff << " ms" << endl;
    }
    else if (diff < 60000) {
        long long sec = diff / 1000;
        long long ms = diff % 1000;
        cout << " Sort time: " << sec << " s " << ms << " ms" << endl;
    } 
    else {
        long long min = diff / 60000;
        diff %= 60000;
        long long sec = diff / 1000;
        long long ms = diff % 1000;
        cout << " Sort time: " << min << " min " << sec << " s " << ms << " ms" << endl;
    }
}

inline void random_vector_and_cnt(vector<int>& a, vector<int>& cnt){
    fill(cnt.begin(), cnt.end(), 0);
    for(int &x : a){
        x = rand() % RANDOM_SIZE + 1;
        cnt[x]++;
    }
}

inline void print_vector(vector<int>& a){
    cout << "\n Print sorted array [Y] yes [N] no" << endl;
    cout << " [?] Enter your choice: ";
    string choice; cin >> choice;
    if(choice == "y" || choice == "Y"){
        cout << "\n Your sorted array: " << endl;
        if(a.size() > MAX_DISPLAY){
            const int MAX_HAFL_DISPLAY = MAX_DISPLAY / 2;
            for(int i = 0; i < MAX_HAFL_DISPLAY; i++){
                cout << " " << a[i];
            }
            cout << " ... ";
            for(int i = a.size() - MAX_HAFL_DISPLAY; i < a.size(); i++){
                cout << " " << a[i];
            }
        } else {
            for(const int &x : a){
                cout << " " << x ;
            }
        }
    }
    cout << endl;
}

#endif