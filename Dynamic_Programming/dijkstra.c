
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int to;
    int w;
    struct Edge *next;
} Edge;

Edge **make_graph(int n) {
    Edge **g = calloc(n, sizeof(Edge *));
    return g;
}

void add_edge(Edge **g, int u, int v, int w) {
    Edge *e = malloc(sizeof(Edge));

    e->to = v;
    e->w = w;
    e->next = g[u];
    g[u] = e;
}

int extract_min(int n, int *visited, int *distance) {
    int idx = -1;
    int best = INT_MAX;
    for (int i = 0; i < n; ++i)
        if (!visited[i] && distance [i] < best) {
            best = distance[i];
            idx = i;
        }
    return idx;
}

int main(void) {
    int n, m;
    printf("Enter number of: vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2)
        return 0;
    Edge **g = make_graph(n);

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        printf("Enter edge %d as: from, to, weight: ", i + 1);
        if (scanf("%d %d %d", &from, &to, &weight) != 3)
            return 0;
        if (from >= 1 && from <= n && to >= 1 && to <= n) {
            from--;
            to--;
        } else if (from < 0 || from >= n || to < 0 || to >= n) {
            continue;
        }
        add_edge(g, from, to, weight);
    }

    int src = 0;
    int dest = 0;
    printf("Enter source vertex: ");
    if (scanf("%d", &src) != 1)
        src = 0;
    if (src >= 1 && src <= n)
        src--;
    else if (src < 0 || src >= n)
        src = 0;

    printf("Enter destination vertex: ");
    if (scanf("%d", &dest) != 1)
        dest = 0;
    if (dest >= 1 && dest <= n)
        dest--;
    else if (dest < 0 || dest >= n)
        dest = 0;


    int *distance = malloc(sizeof(int) * n);
    int *visited = calloc(n, sizeof(int));
    int *parent = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[src] = 0;


    for (int it = 0; it < n; ++it)
    {
        int u = extract_min(n, visited, distance);
        if (u == -1)
            break;
        visited[u] = 1;
        if (u == dest)
            break;
        for (Edge *e = g[u]; e; e = e->next)
        {
            int v = e->to;
            int w = e->w;
            if (!visited[v] && distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }

    if (distance[dest] == INT_MAX)
        printf("INF\n");
    else
        printf("%d\n", distance[dest]);



    for (int i = 0; i < n; ++i)
    {
        Edge *e = g[i];
        while (e)
        {
            Edge *t = e;
            e = e->next;
            free(t);
        }
    }
    free(distance);
    free(visited);
    free(parent);
    return 0;
}

