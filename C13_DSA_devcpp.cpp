#include <iostream>
using namespace std;

const int n = 10;

string landmarks[n] = {
   "Front Gate", "Administration", "Reading Room", "Food Court",
   "Assembly Hall", "Sports Complex", "Hostel Block", "Car Park",
   "Lecture Hall", "Botanical Garden"
};

class Queue {
   int arr[n];
   int front, rear;
public:
   Queue() {
       front = rear = -1;
   }

   bool isEmpty() {
       return front == -1;
   }
   bool isFull() {
       return rear == n - 1;
   }

   void enqueue(int x) {
       if (isFull()) {
           cout << "Queue is full!\n";
           return;
       }
       if (isEmpty()) {
           front = rear = 0;
       } else {
           rear++;
       }
       arr[rear] = x;
   }

   int dequeue() {
       if (isEmpty()) {
           cout << "Queue is empty!\n";
           return -1;
       }
       int val = arr[front];
       if (front == rear) {
           front = rear = -1;
       } else {
           front++;
       }
       return val;
   }
};

class Graph {
   int adjMatrix[n][n]; 
   int adjList[n][n];   
   int visited[n];
   int size[n];         
public:
   Graph() {
       for (int i = 0; i < n; i++) {
           visited[i] = 0;
           size[i] = 0;
           for (int j = 0; j < n; j++) {
               adjMatrix[i][j] = 0;
               adjList[i][j] = -1;
           }
       }
   }

   void readGraph() {
       int v, e;
       cout << "Enter number of landmarks: ";
       cin >> v;
       cout << "Enter number of connections (edges): ";
       cin >> e;

       cout << "Landmark Indices:\n";
       for (int i = 0; i < v; i++) {
           cout << i << ": " << landmarks[i] << endl;
       }

       int x, y;
       for (int i = 0; i < e; i++) {
           cout << "Enter connected landmarks (x y): ";
           cin >> x >> y;
           adjMatrix[x][y] = adjMatrix[y][x] = 1;
           adjList[x][size[x]++] = y;
           adjList[y][size[y]++] = x;
       }
   }

   void dfs(int x) {
       visited[x] = 1;
       cout << landmarks[x] << "->";
       for (int i = 0; i < n; i++) {
           if (adjMatrix[x][i] == 1 && !visited[i]) {
               dfs(i);
           }
       }
   }

   void bfs(int start) {
       for (int i = 0; i < n; i++) visited[i] = 0;

       Queue q;
       q.enqueue(start);
       visited[start] = 1;

       while (!q.isEmpty()) {
           int current = q.dequeue();
           cout << landmarks[current] << "->";

           for (int i = 0; i < size[current]; i++) {
               int neighbor = adjList[current][i];
               if (!visited[neighbor]) {
                   visited[neighbor] = 1;
                   q.enqueue(neighbor);
               }
           }
       }
   }
};

int main() {
    Graph g;
    g.readGraph();
    
    int choice, startNode;

    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Perform DFS\n";
        cout << "2. Perform BFS\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the starting node for DFS (0-" << n - 1 << "): ";
                cin >> startNode;
                if (startNode >= 0 && startNode < n) {
                    cout << "DFS Traversal: ";
                    g.dfs(startNode);
                } else {
                    cout << "Invalid node! Please enter a node between 0 and " << n - 1 << ".\n";
                }
                break;
            case 2:
                cout << "Enter the starting node for BFS (0-" << n - 1 << "): ";
                cin >> startNode;
                if (startNode >= 0 && startNode < n) {
                    cout << "BFS Traversal: ";
                    g.bfs(startNode);
                } else {
                    cout << "Invalid node! Please enter a node between 0 and " << n - 1 << ".\n";
                }
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 3);

    return 0;
}