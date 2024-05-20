#include <bits/stdc++.h>
using namespace std;

#define V 4 // Número de vértices no grafo
#define INF 99999 // Definir um valor para representar a ausência de caminho direto entre dois vértices.

void imprimirSolucao(int dist[][V]); // Declaração da função para imprimir a solução final

void floydWarshall(int dist[][V]) {
    int i, j, k;
    // Laços atrelados para encontrar os caminhos mais curtos
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // Se o vértice k está no caminho mais curto de i para j, atualize dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    imprimirSolucao(dist); // Chama a função para imprimir a solução final
}

void imprimirSolucao(int dist[][V]) {
    // Imprime a matriz de distâncias mais curtas
    cout << "A matriz a seguir mostra as distâncias mais curtas entre cada par de vértices\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    // Matriz de adjacência do grafo de entrada
    int grafo[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    floydWarshall(grafo); // Executa o algoritmo de Floyd-Warshall
    return 0;
}
