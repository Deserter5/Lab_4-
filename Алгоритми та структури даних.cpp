#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "search.h"

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(NULL));

    int N, K;

    cout << "Enter array size (N): ";
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    cout << "Enter search key (K): ";
    cin >> K;

    auto start_S = high_resolution_clock::now();
    int pos_S = sequentialSearch_S(arr, K);
    auto stop_S = high_resolution_clock::now();
    auto duration_S = duration_cast<nanoseconds>(stop_S - start_S);

    auto start_Q = high_resolution_clock::now();
    int pos_Q = quickSequentialSearch_Q(arr, K);
    auto stop_Q = high_resolution_clock::now();
    auto duration_Q = duration_cast<nanoseconds>(stop_Q - start_Q);

    cout << "\nAlgorithm S:" << endl;
    if (pos_S != -1) {
        cout << "Found at index " << pos_S << endl;
    }
    else {
        cout << "Not found" << endl;
    }
    cout << "Time: " << duration_S.count() << " ns" << endl;

    cout << "\nAlgorithm Q:" << endl;
    if (pos_Q != -1) {
        cout << "Found at index " << pos_Q << endl;
    }
    else {
        cout << "Not found" << endl;
    }
    cout << "Time: " << duration_Q.count() << " ns" << endl;

    int check_pos;
    cout << "\nEnter index to check element: ";
    cin >> check_pos;
    if (check_pos >= 0 && check_pos < N) {
        cout << "Element at index " << check_pos << " is: " << arr[check_pos] << endl;
    }
    else {
        cout << "Index out of bounds!" << endl;
    }

    return 0;
}