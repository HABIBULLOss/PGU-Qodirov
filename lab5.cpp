#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

    Graph(int V) : vertices(V), adjacencyMatrix(V, vector<int>(V, 0)) {}

    void addEdge(int v, int w) {
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1; // Для неориентированного графа
    }

    void printIncidenceMatrix() {
        int edges = 0;
        setlocale(LC_ALL, "rus");
        for (int i = 0; i < vertices; ++i) {
            for (int j = i + 1; j < vertices; ++j) {
                if (adjacencyMatrix[i][j] == 1) {
                    edges++;
                }
            }
        }

        vector<vector<int>> incidenceMatrix(vertices, vector<int>(edges, 0));

        int edgeIndex = 0;
        for (int j = 0; j < vertices; ++j) {
            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[i][j] == 1) {
                    incidenceMatrix[i][edgeIndex] = -1;
                    incidenceMatrix[j][edgeIndex] = 1;
                    edgeIndex++;
                }
            }
        }

        // Вывод матрицы инцидентности
        cout << "матрицы инцидентности:" << endl;
        for (const auto &row : incidenceMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        // Определение размера графа
        cout << "размер графа: " << vertices << endl;

        // Поиск концевых вершин
        cout << "Terminal vertices: ";
        for (int i = 0; i < vertices; ++i) {
            int sum = 0;
            for (int j = 0; j < vertices; ++j) {
                sum += adjacencyMatrix[i][j];
            }
            if (sum == 1) {
                cout << i << " ";
            }
        }
        cout << endl;

        // Поиск изолированных вершин
        cout << "изолированных вершин: ";
        for (int i = 0; i < vertices; ++i) {
            int sum = 0;
            for (int j = 0; j < vertices; ++j) {
                sum += adjacencyMatrix[i][j];
            }
            if (sum == 0) {
                cout << i << " ";
            }
        }
        cout << endl;

        // Поиск доминирующих вершин
        cout << "доминирующих вершин: ";
        for (int i = 0; i < vertices; ++i) {
            bool dominates = true;
            for (int j = 0; j < vertices; ++j) {
                if (i != j && adjacencyMatrix[i][j] == 0) {
                    dominates = false;
                    break;
                }
            }
            if (dominates) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(4); // Пример с графом из 4 вершин

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    // Вывод матрицы инцидентности и характеристик графа
    g.printIncidenceMatrix();

    return 0;
}
