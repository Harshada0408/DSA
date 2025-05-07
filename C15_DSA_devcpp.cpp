#include <iostream>
using namespace std;

class Graph {
    int cost;
    int adjMatrix[5][5];
    int b[5][5];
    int visited[5];
    int distance[5];
    int from[5];
    int n;

public:

    Graph(int nodes) {
        n = nodes;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
                b[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            distance[i] = 100000; 
            from[i] = -1; 
        }
    }

    void readGraph() {
        int v, x, y;
        cout << "Enter number of edges: ";
        cin >> v;
        for (int i = 0; i < v; i++) {
            cout << "Enter connected cities (x y): ";
            cin >> x >> y;
            cout << "Enter cost of the edge: ";
            cin >> cost;
            adjMatrix[x][y] = cost;
            adjMatrix[y][x] = cost;
        }
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims() {
        visited[0] = 1;
        distance[0] = 0;
        int edgeCount = 0;
        int minCost = 0;
        while (edgeCount < n - 1) {
            int min = 100000; 
            int u = -1;

            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    for (int j = 0; j < n; j++) {
                        if (!visited[j] && adjMatrix[i][j] != 0 && adjMatrix[i][j] < min) {
                            min = adjMatrix[i][j];
                            u = j;
                        }
                    }
                }
            }
            if (u == -1) {
                cout << "No MST found." << endl;
                return;
            }
            visited[u] = 1;
            minCost += min;
            edgeCount++;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && adjMatrix[u][i] != 0 && adjMatrix[u][i] < distance[i]) {
                    distance[i] = adjMatrix[u][i];
                    from[i] = u;
                }
            }
        }
        cout << "Minimum cost of connecting all offices: " << minCost << endl;
    }
};

int main() {
    int nodes;
    cout << "Enter number of nodes (offices): ";
    cin >> nodes;
    Graph g(nodes);
    g.readGraph();
    g.printGraph();
    g.prims();
    return 0;
}


