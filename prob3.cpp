#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    // the same as prob2'code
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

    // new remove code
    int Remove() {   // ← added method
        if (heap.empty()) {   
            throw runtime_error("Heap is empty."); 
        }

        int rootValue = heap[0];  

        heap[0] = heap.back();    
        heap.pop_back();        

        // Bubble down from the root to restore the heap property
        int i = 0, n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left >= n) break;

            int largest = left;
            if (right < n && heap[right] > heap[left])
                largest = right;

            // If the parent is already larger than both children, stop
            if (heap[i] >= heap[largest]) break;

            // Otherwise, swap with the larger child
            swap(heap[i], heap[largest]);
            i = largest;
        }

        return rootValue; 
    }

    // for debugging
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

    h.Print(); 

    cout << "Removed: " << h.Remove() << endl;  
    h.Print();

    return 0;
}
