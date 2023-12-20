#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Генерация матрицы смежности для неориентированного графа
vector<vector<int>> generateGraph(int vertices, int edges) {
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    srand(time(0));

    for (int i = 0; i < edges; ++i) {
        int vertex1 = rand() % vertices;
        int vertex2 = rand() % vertices;

        // Гарантируем, что не создаем петли и не повторяем ребра
        while (vertex1 == vertex2 || graph[vertex1][vertex2] == 1 || graph[vertex2][vertex1] == 1) {
            vertex1 = rand() % vertices;
            vertex2 = rand() % vertices;
        }

        // Добавляем ребро между вершинами
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    return graph;
}

// Обход в глубину
void dfs(const vector<vector<int>>& graph, int vertex, unordered_set<int>& visited) {
    if (visited.find(vertex) == visited.end()) {
        cout << vertex << ' ';
        visited.insert(vertex);
        for (int neighbor = 0; neighbor < graph[vertex].size(); ++neighbor) {
            if (graph[vertex][neighbor] == 1) {
                dfs(graph, neighbor, visited);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    // Генерация графа
    int vertices = 5;
    int edges = 7;
    vector<vector<int>> graph = generateGraph(vertices, edges);

    // Вывод матрицы смежности
    cout << "Матрица смежности:\n";
    for (const auto& row : graph) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }

    // Вызов DFS с начальной вершиной 0
    cout << "\nОбход в глубину:\n";
    unordered_set<int> visited;
    dfs(graph, 0, visited);

    return 0;
}
