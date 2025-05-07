#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; ++i) {
        cin >> marks[i];
    }

    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (int i = 0; i < n; ++i) {
    	maxHeap.push(marks[i]);
		minHeap.push(marks[i]);
	}


    cout << "Maximum Marks: " << maxHeap.top() << endl;
    cout << "Minimum Marks: " << minHeap.top() << endl;

    return 0;
}