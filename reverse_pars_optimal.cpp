#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return 0; // no pairs counted here, just merging
}

// ✅ Count reverse pairs across the two halves
int countPairs(vector<int>& arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high); // ✅ count reverse pairs
    merge(arr, low, mid, high);            // ✅ merge sorted halves

    return cnt;
}

int main() {
    vector<int> a = {4, 1, 2, 3, 1};
    int n = a.size();
    int cnt = mergeSort(a, 0, n - 1);
    cout << cnt << endl; // expected output = 3
}
