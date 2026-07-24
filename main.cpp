// TÁC GIẢ: TRƯỜNG CHINH (NTC++)
// GITHUB: GITHUB.COM/TRGCHINHH

// CHƯƠNG TRÌNH ĐO THỜI GIAN CHẠY CỦA 18 THUẬT TOÁN SẮP XẾP NỔI TIẾNG HIỆN NAY TRONG C++

//   _____  ____  _____ _______            _      _____  ____  _____  _____ _______ _    _ __  __ 
//  / ____|/ __ \|  __ \__   __|     /\   | |    / ____|/ __ \|  __ \|_   _|__   __| |  | |  \/  |
// | (___ | |  | | |__) | | |       /  \  | |   | |  __| |  | | |__) | | |    | |  | |__| | \  / |
//  \___ \| |  | |  _  /  | |      / /\ \ | |   | | |_ | |  | |  _  /  | |    | |  |  __  | |\/| |
//  ____) | |__| | | \ \  | |     / ____ \| |___| |__| | |__| | | \ \ _| |_   | |  | |  | | |  | |
// |_____/ \____/|_|  \_\ |_|    /_/    \_\______\_____|\____/|_|  \_\_____|  |_|  |_|  |_|_|  |_|
                                                                                        
// MIT LICENSE 2026        

#include "include.h"

int main(){
    vector<int> a(RANDOM_SIZE);
    vector<int> cnt(RANDOM_SIZE, 0);

    print_banner(BANNER);
    enter_random_size(RANDOM_SIZE, a, cnt);

    while(1){
        print_banner(BANNER);

        cout << " [+] Random size: " << RANDOM_SIZE << "\n\n";

        print_menu();
        c_srand();
        random_vector_and_cnt(a, cnt);
        cout << "\n [?] Enter option: ";
        int choice; cin >> choice;

        datetime start_time = timenow();  

        if(choice == 0){
            enter_random_size(RANDOM_SIZE, a, cnt);
            continue;
        }
        else if(choice == 1)        bubble_sort(a);
        else if(choice == 2)        selection_sort(a);
        else if(choice == 3)        insertion_sort(a);
        else if(choice == 4)        binary_insertion_sort(a);
        else if(choice == 5)        shaker_sort(a);
        else if(choice == 6)        shell_sort(a);
        else if(choice == 7)        quick_sort(a, 0, a.size() - 1);
        else if(choice == 8)        merge_sort(a, 0, a.size() - 1);
        else if(choice == 9)        heap_sort(a);
        else if(choice == 10)       counting_sort(a, cnt);
        else if(choice == 11)       radix_sort(a);
        else if(choice == 12)       bucket_sort(a);
        else if(choice == 13)       flash_sort(a);
        else if(choice == 14)       tim_sort(a);
        else if(choice == 15)       intro_sort(a);
        else if(choice == 16)       comb_sort(a);
        else if(choice == 17)       gnome_sort(a);
        else if(choice == 18)       tree_sort(a);
        else if(choice == 19) {
            cout << " Goodbye !" << endl;
            exit(0);
        }
        else cout << " Invalid option !" << endl;
        
        datetime end_time = timenow();
        cout << endl << " Sort completed" << endl;
        print_timedelta(start_time, end_time);
        print_vector(a);

        pause_program();
    }
}
