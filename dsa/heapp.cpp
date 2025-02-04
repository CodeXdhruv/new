#include <iostream>
using namespace std;

#define MAX 100
int heap[MAX];
int size = 0;

// Function to insert an element into the max heap
void insert(int value) {
    size++;
    int index = size;
    heap[index] = value;

    // Bubble up to maintain max-heap property
    while (index > 1) {
        int parent = index / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            return;
        }
    }
}

// Function to delete the root (maximum) element from the heap
void deleteFromHeap() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    heap[1] = heap[size];
    size--;

    int i = 1;
    while (i <= size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

// Heapify function to build a max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to display the heap
void display() {
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    // Insert elements into the heap
    insert(5);
    insert(10);
    insert(3);
    insert(1);
    insert(7);

    cout << "Heap after insertion: ";
    display();

    deleteFromHeap();
    cout << "Heap after deletion: ";
    display();

    // Build a max heap from an array
    int arr[MAX] = {-1, 3, 4, 5, 6, 9}; // -1 is a placeholder for 1-based indexing
    int n = 5;

    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    cout << "Heapified array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
