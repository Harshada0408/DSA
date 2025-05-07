#include <iostream>
using namespace std;

// ?? Max-heapify function
void maxHeapify(int arr[], int n, int i) {
    int largest = i;        
    int left = 2*i + 1;    
    int right = 2*i + 2;   

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// ?? Min-heapify function
void minHeapify(int arr[], int n, int i) {
    int smallest = i;     
    int left = 2*i + 1;   
    int right = 2*i + 2;  

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int original[n];
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    // Copy into separate arrays for each heap
    int maxHeap[n], minHeap[n];
    for (int i = 0; i < n; i++) {
        maxHeap[i] = original[i];
        minHeap[i] = original[i];
    }

    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(maxHeap, n, i);

    // Build Min-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(minHeap, n, i);

    cout << "Maximum Marks: " << maxHeap[0] << endl;
    cout << "Minimum Marks: " << minHeap[0] << endl;

    return 0;
}