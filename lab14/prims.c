#include <stdio.h>

void main()
{
    int i, j, edges = 0;
    int a, b, min, min_cost = 0;
    int cost[50][50], n, visited[50] = {0};

    // Taking graph as input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    // Finding minimum cost
    visited[0] = 1;

    while (edges < n - 1)
    {
        min = 9999;
        for (i = 0; i < n; i++) 
            if (visited[i]) 
            {
                for (j = 0; j < n; j++) 
                {
                    if (min > cost[i][j] && !visited[j]) 
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%c-->%c | Cost: %d\n", a + 65, b + 65, min);
        visited[b] = 1; // marking destination vertex as visited
        min_cost += min;
        edges++;
    }

    printf("Minimum Cost: %d\n", min_cost);
}

/*Enter the number of vertices: 6
Enter cost matrix:
999 20 9 13 999 999
20 999 1 999 4 5
9 1 999 2 999 999
13 999 2 999 3 14
999 4 999 3 999 999
999 5 999 14 999 999
A-->C | Cost: 9
C-->B | Cost: 1
C-->D | Cost: 2
D-->E | Cost: 3
B-->F | Cost: 5
Minimum Cost: 20
*/
