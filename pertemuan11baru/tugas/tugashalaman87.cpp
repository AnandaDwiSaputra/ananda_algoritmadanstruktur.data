#include <iostream>
#include <vector>
#include <queue>
#include <limits> 

#define M std::numeric_limits<int>::max()

using namespace std;

const int N = 6;

void printPath(int R[], int node) {
    if (R[node] == -1) {
        cout << node + 1; 
        return;
    }

    printPath(R, R[node]);

    cout << " -> " << node + 1;
}

void dijkstra(int graph[N][N], int source) {

    int Q[N], R[N];
    for (int i = 0; i < N; i++) {
        Q[i] = M;
        R[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    Q[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int v = 0; v < N; v++) {

            if (graph[u][v] != M) {
                int w = graph[u][v]; 
                if (Q[v] > Q[u] + w) {
                    Q[v] = Q[u] + w; 
                    R[v] = u;       
                    pq.push(make_pair(Q[v], v)); 
                }
            }
        }
    }

    cout << "\nJarak dari simpul " << source + 1 << " ke semua simpul:\n";
    for (int i = 0; i < N; i++) {
        if (Q[i] == M) {
            cout << "Node " << source + 1 << " -> " << i + 1 << " = Tidak terjangkau\n";
        } else {
            cout << "Node " << source + 1 << " -> " << i + 1 << " = " << Q[i] << endl;
        }
    }

    cout << "\nRute terpendek:\n";
    for (int i = 0; i < N; i++) {
        cout << "Ke " << i + 1 << ": ";
        if (Q[i] == M) {
            cout << "Tidak ada jalur\n";
        } else {
            printPath(R, i); 
            cout << endl;
        }
    }
}

int main() {

    int graph[N][N] = {

        {0, 7, 9, M, M, 14},  
        {7, 0, 10, 15, M, M}, 
        {9, 10, 0, 11, M, 2}, 
        {M, 15, 11, 0, 6, M}, 
        {M, M, M, 6, 0, 9},   
        {14, M, 2, M, 9, 0}   
    };

    int source_node_input; // Variable to store user input (1-6)
    cout << "Masukkan simpul asal (1-6): ";
    cin >> source_node_input;

    int source_index = source_node_input - 1;

    if (source_index < 0 || source_index >= N) {
        cout << "Input simpul asal tidak valid. Harap masukkan angka antara 1 dan " << N << ".\n";
        return 1; // Indicate an error
    }

    dijkstra(graph, source_index);

    return 0;
}
