#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];   
    int i = l - 1;        

    for (int j = l; j < r; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quicksort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quicksort(arr, l, p - 1);  
        quicksort(arr, p + 1, r);  
    }
}

int main() {
    //example:
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    quicksort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
