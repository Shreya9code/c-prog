#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

int graph[MAX][MAX];  // Adjacency matrix for the graph
int vertices;  // Number of vertices

// Function to check for K5 subgraph (Complete graph on 5 vertices)
bool checkK5() {
    int count = 0;
    // Check all combinations of 5 vertices and see if they form a K5 subgraph
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            for (int k = j + 1; k < vertices; k++) {
                for (int l = k + 1; l < vertices; l++) {
                    for (int m = l + 1; m < vertices; m++) {
                        if (graph[i][j] && graph[i][k] && graph[i][l] && graph[i][m] &&
                            graph[j][k] && graph[j][l] && graph[j][m] &&
                            graph[k][l] && graph[k][m] && graph[l][m]) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count > 0;
}

// Function to check for K3,3 subgraph (Complete bipartite graph on 6 vertices)
bool checkK33() {
    // Partition the vertices into two sets of 3 and check if it's a K3,3 subgraph
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            for (int k = j + 1; k < vertices; k++) {
                for (int l = 0; l < vertices; l++) {
                    if (l != i && l != j && l != k) {
                        for (int m = l + 1; m < vertices; m++) {
                            if (m != i && m != j && m != k) {
                                for (int n = m + 1; n < vertices; n++) {
                                    if (n != i && n != j && n != k) {
                                        if (graph[i][l] && graph[i][m] && graph[i][n] &&
                                            graph[j][l] && graph[j][m] && graph[j][n] &&
                                            graph[k][l] && graph[k][m] && graph[k][n]) {
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (checkK5() || checkK33()) {
        printf("The graph is non-planar.\n");
    } else {
        printf("The graph is planar.\n");
    }

    return 0;
}