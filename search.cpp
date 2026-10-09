#include "search.h"

int sequentialSearch_S(const std::vector<int>& arr, int K) {
    int N = arr.size();
    for (int i = 0; i < N; i++) {
        if (arr[i] == K) {
            return i;
        }
    }
    return -1;
}

int quickSequentialSearch_Q(std::vector<int>& arr, int K) {
    int N = arr.size();
    arr.push_back(K);

    int i = 0;
    while (arr[i] != K) {
        i++;
    }

    arr.pop_back();

    if (i < N) {
        return i;
    }
    else {
        return -1;
    }
}