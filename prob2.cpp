#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    // Add a new value into the heap
    void Add(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        // Bubble up
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] >= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    // Optional: print heap (for debugging)
    void Print() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.Add(10);
    h.Add(5);
    h.Add(30);
    h.Add(2);

    h.Print(); // 30 is at the top
    return 0;
}
