#include <stdio.h>

#define MAX 5

void depth_first_search(int adj[][MAX], int visited[], int start)
{
    int stack[MAX];
    int top = -1, i;

    // Visit the start node
    printf("%c-", start + 65);
    visited[start] = 1;
    stack[++top] = start;

    while (top != -1)
    {
        start = stack[top];

        // Search for an unvisited adjacent node
        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                printf("%c-", i + 65);
                visited[i] = 1;
                break;
            }
        }

        // If no unvisited neighbor found, pop the stack
        if (i == MAX)
            top--;
    }
}

int main()
{
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int i, j;

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);

    printf("DFS Traversal: ");
    depth_first_search(adj, visited, 0);
    printf("\n");

    return 0;
}

