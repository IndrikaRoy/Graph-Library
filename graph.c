//		G#: G01210152		NAME: Indrika Roy

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "graph.h"
#include <string.h>

Graph *graph_initialize()                                     //initialising matrix
{
    int i = 0, j = 0, k = 0;
    Graph *graph_init = malloc(sizeof(Graph));
    if (graph_init == NULL)
    {
        return NULL;
    }
    else
    {
        graph_init->max_vertex = 0;
        for (i = 0; i < MAX_VERTICES; i++)
        {
            for (j = 0; j < MAX_VERTICES; j++)
            {
                graph_init->adj_matrix[i][j] = -1;            //initialising all values of rows and columns to -1
            }
        }
        for (k = 0; k < MAX_VERTICES; k++)
        {
            graph_init->visited[k] = 0;
        }
        return graph_init;
    }
}

int graph_add_vertex(Graph *graph, int v1)
{
    int i = 0;
    int j = 0;
    if (graph == NULL)
    {
        return -1;
    }
    else if (v1 < 0 || v1 > MAX_VERTICES)                       //checking if the matrix is valid
    {   
        return -1;                                              
    }
    else if (graph->adj_matrix[v1][v1] != -1)
    {
        return 0;
    }
    else if (graph->adj_matrix[v1][v1] == -1)
    {
        for (i = 0; i <= MAX_VERTICES; i++)
        {
            graph->adj_matrix[i][v1] = 0;                        
        }
        for (j = 0; j <= MAX_VERTICES; j++)
        {
            graph->adj_matrix[v1][j] = 0;                       //initialising row and column of active vertex to 0
        }
    }
    else
    {
        return -1;
    }
}

int graph_contains_vertex(Graph *graph, int v1)
{
    int j = 0;
    for (j = 0; j < MAX_VERTICES; j++)
    {
        if (graph->adj_matrix[v1][j] != -1)                  //if graph contains vertex then function will return 1 else 0
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int graph_remove_vertex(Graph *graph, int v1)
{
    int i = 0;
    int j = 0;
    if (graph == NULL)
    {
        return -1;
    }
    else if (v1 < 0 || v1 > MAX_VERTICES)                       //if vertex is invalid, return error
    {
        return -1;
    }
    else if (graph->adj_matrix[v1][v1] == -1)
    {
        return 0;
    }
    else if (graph->adj_matrix[v1][v1] != -1)
    {
        for (i = 0; i < MAX_VERTICES; i++)
        {
            graph->adj_matrix[i][v1] = -1;
        }
        for (j = 0; j < MAX_VERTICES; j++)
        {
            graph->adj_matrix[v1][j] = -1;                      //initialising row and column of vertex removed to -1
        }
        return 0;
    }
}

int graph_add_edge(Graph *graph, int v1, int v2, int wt)
{
    if (graph == NULL)
    {
        return -1;
    }
    else if (graph->adj_matrix[v1][v1] == -1 || graph->adj_matrix[v2][v2] == -1)
    {
        return -1;                                                    //if either v1 or v2 does not exist the return error
    }
    else if (graph->adj_matrix[v1][v1] >= 0 && graph->adj_matrix[v2][v2] >= 0)
    {
        graph->adj_matrix[v1][v2] = wt;                            //if both v1 and v2 exist then add the edge with weight
        return 0;
    }
    else
    {
        return -1;
    }
}

int graph_contains_edge(Graph *graph, int v1, int v2)
{
    if (graph->adj_matrix[v1][v2] > 0)                      //this means graph contains edge
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int graph_remove_edge(Graph *graph, int v1, int v2)
{
    if (graph->adj_matrix[v1][v1] >= 0 && graph->adj_matrix[v2][v2] >= 0)       //if vertices exist, remove edge
    {
        graph->adj_matrix[v1][v2] = 0;
        return 0;
    }
    else
    {
        return -1;
    }
}

int graph_num_vertices(Graph *graph)
{
    if (graph == NULL)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int count_v = 0;                                      //to count total vertices in graph
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][i] != -1)
            {
                (count_v)++;
            }
        }
        return count_v;
    }
}

int graph_num_edges(Graph *graph)
{
    int i = 0;
    int j = 0;
    int count_e = 0;                                        // to count total edges in graph
    if (graph == NULL)
    {
        return -1;
    }
    else
    {
        for (i = 0; i < MAX_VERTICES; i++)
        {
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->adj_matrix[i][j] > 0)
                {
                    (count_e)++;
                }
            }
        }
        return count_e;
    }
}

int graph_total_weight(Graph *graph)
{
    if (graph == NULL)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int temp = 0;
        int j = 0;
        for (i = 0; i < MAX_VERTICES; i++)
        {
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->adj_matrix[i][j] > 0)
                {
                    temp = temp + graph->adj_matrix[i][j];
                }
            }
        }
        return temp;                                        //returns the total weight of the edges in the graph
    }
}

int graph_get_degree(Graph *graph, int v1)
{
    if (graph == NULL)
    {
        return -1;
    }
    else if (graph->adj_matrix[v1][v1] == -1)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int j = 0;
        int count = 0;
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][v1] > 0)
            {
                count++;
            }
        }

        for (j = 0; j < MAX_VERTICES; j++)
        {
            if (graph->adj_matrix[v1][j] > 0)
            {
                count++;
            }
        }
        return count;                                       // to fetch the degree of vertex v1 in the graph
    }
}

int graph_get_edge_weight(Graph *graph, int v1, int v2)
{
    if (graph == NULL)
    {
        return -1;
    }
    else if (graph->adj_matrix[v1][v1] == -1 || graph->adj_matrix[v2][v2] == -1)
    {
        return -1;
    }
    else if (graph->adj_matrix[v1][v2] > 0)
    {
        return graph->adj_matrix[v1][v2];                   //to return the edge weight between v1 and v2
    }
}

int graph_is_neighbor(Graph *graph, int v1, int v2)         //to check if v1 and v2 are connected
{
    if (graph == NULL)
    {    
        return 0;
    }
    else if (graph->adj_matrix[v1][v1] == -1 || graph->adj_matrix[v2][v2] == -1)
    {    
        return 0;
    }
    else if (graph->adj_matrix[v1][v2] > 0 || graph->adj_matrix[v2][v1] > 0)
    {   
        return 1;
    }
}

int *graph_get_predecessors(Graph *graph, int v1)  
{
    if (graph == NULL)
    {
        return NULL;
    }
    else if (graph->adj_matrix[v1][v1] == -1)
    {
        return NULL;
    }
    else
    {
        int i = 0;
        int count = 0;
        int *get_pred = malloc(sizeof(int) * MAX_VERTICES);
        for (i = 0; i < MAX_VERTICES; i++)
        {
            *(get_pred + i) = -1;
        }

        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][v1] > 0)
            {
                *(get_pred + count) = i;
                count++;
            }
        }
        return get_pred;                                    //to get all the preceding vertices of a vertex v1
    }
}

int *graph_get_successors(Graph *graph, int v1)
{
    if (graph == NULL)
    {
        return NULL;
    }
    else if (graph->adj_matrix[v1][v1] == -1)
    {
        return NULL;
    }
    else
    {
        int j = 0;
        int count = 0;
        int *get_succ = malloc(sizeof(int) * MAX_VERTICES);
        for (j = 0; j < MAX_VERTICES; j++)
        {
            *(get_succ + j) = -1;
        }

        for (j = 0; j < MAX_VERTICES; j++)
        {
            if (graph->adj_matrix[v1][j] > 0)
            {
                *(get_succ + count) = j;
                count++;
            }
        }
        return get_succ;                                    // to get all the succeeding vertices of a vertex v1
    }
}

int graph_has_path(Graph *graph, int v1, int v2)            // to check if path exists between v1 and v2
{
    int queue[100];
    int *ptr = NULL;
    int count = 0;
    int counter = 0;
    int k = 0;
    int i = 0;
    if (graph == NULL)
    {
        return 0;
    }
    else if (graph->adj_matrix[v1][v1] == -1 || graph->adj_matrix[v2][v2] == -1)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < 100; i++)
        {
            queue[i] = -1;                                  //initialising queue as empty
        }
        ptr = graph_get_successors(graph, v1);              //to get successors of vertex v1
        while (*(ptr + count) != -1)
        {
            queue[count] = *(ptr + count);                  //to enqueue the successors of v1 in queue
            printf("%d", queue[count]);
            graph->visited[queue[count]] = 1;
            if (queue[v2] == 1)
            {
                return 1;
            }
            count++;
        }

        while (queue[k] != -1)
        {
            counter = 0;
            ptr = graph_get_successors(graph, queue[k]);    
            while (*(ptr + counter) != -1)                  //to check till no successors found
            {
                if (graph->visited[*(ptr + counter)] == 0)
                {
                    queue[count] = *(ptr + counter);
                    graph->visited[queue[count]] = 1;
                    count++;
                    counter++;
                }
                else
                {
                    counter++;
                }
            }
            if (queue[k] == v2)                                 //if v2 found in queue then path exists
            {
                return 1;
            }
            k++;
        }
        return 0;
    }
}

void graph_print(Graph *graph)
{
    int i = 0;
    int j = 0;
    if (graph == NULL)
    {
        return;
    }
    else
    {
        for (i = 0; i < MAX_VERTICES; i++)
        {
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->adj_matrix[i][j] > -1 && i == j)
                {
                    printf("  %d", j);                       // to print vertices present in the graph
                }
            }
        }
        printf("\n");
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][i] > -1)
            {
                printf("%d", i);
                for (j = 0; j < MAX_VERTICES; j++)
                {
                    if (graph->adj_matrix[j][j] > -1)
                    {
                        printf(" %d ", graph->adj_matrix[i][j]); //to print the edges in the graph
                    }
                }
                printf("\n");
            }
        }
    }
}

void graph_output_dot(Graph *graph, char *filename)         //to print graph in GraphViz program format
{
    if (graph == NULL)
    {
        return;
    }
    else
    {
        int i = 0;
        int j = 0;
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
        {
            return;
        }
        fprintf(fp, "digraph {\n");
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][i] >= 0)
            {
                fprintf(fp, "%d;\n", i);
                for (j = 0; j < MAX_VERTICES; j++)
                {
                    if (graph->adj_matrix[j][j] >= 0)
                    {
                        if (graph->adj_matrix[i][j] > 0)
                        {
                            fprintf(fp, "%d -> %d [label = %d];\n", i, j, graph->adj_matrix[i][j]);
                        }
                    }
                }
            }
        }
        fprintf(fp, "}");
        fclose(fp);
    }
}

int graph_load_file(Graph *graph, char *filename)
{
    char buffer[FILE_ENTRY_MAX_LEN] = {0};                  //initialising the buffer to read from the file from which 
    char *a = NULL;                                         //graph will be loaded
    int v1 = 0;
    int v2 = 0;
    int wt = 0;
    int i = 0, j = 0, k = 0;
    FILE *fp = fopen(filename, "r");
    if (graph == NULL)
    {
        return -1;
    }
    else
    {
        for (i = 0; i < MAX_VERTICES; i++)
        {
            for (j = 0; j < MAX_VERTICES; j++)
            {
                graph->adj_matrix[i][j] = -1;
            }
        }
        for (k = 0; k < MAX_VERTICES; k++)
        {
            graph->visited[k] = 0;
        }

        while (feof(fp) == 0)                               // if end of file reached
        {
            fgets(buffer, sizeof(buffer), fp);
            a = strtok(buffer, ",");
            sscanf(a, "%d", &v1);
            a = strtok(NULL, ",");
            if (a == NULL)
            {
                graph_add_vertex(graph, v1);
                continue;
            }
            else
            {
                sscanf(a, "%d", &v2);
                a = strtok(NULL, ",");
                sscanf(a, "%d", &wt);
                if (graph->adj_matrix[v1][v1] == -1)
                {
                    graph_add_vertex(graph, v1);
                }
                if (graph->adj_matrix[v2][v2] == -1)
                {
                    graph_add_vertex(graph, v2);
                }
                graph_add_edge(graph, v1, v2, wt);
            }
        }
    }
    fclose(fp);
}

int graph_save_file(Graph *graph, char *filename)           //to save our graph to a file
{
    if (graph == NULL)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int j = 0;
        int k = 0;
        int flag = 0;
        FILE *fp = fopen(filename, "w");
        for (i = 0; i < MAX_VERTICES; i++)
        {
            flag = 0;
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (graph->adj_matrix[i][j] > 0)
                {
                    flag = 1;
                }
            }
            for (k = 0; k < MAX_VERTICES; k++)
            {
                if (graph->adj_matrix[k][i] > 0)
                {
                    flag = 1;
                }
            }
            if (flag == 0 && graph->adj_matrix[i][i] > -1)
            {
                fprintf(fp, "%d\n", i);
            }
        }

        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (graph->adj_matrix[i][i] > -1)
            {
                for (j = 0; j < MAX_VERTICES; j++)
                {
                    if (graph->adj_matrix[j][j] > -1)
                    {
                        if (graph->adj_matrix[i][j] > 0)
                        {
                            fprintf(fp, "%d,%d,%d\n", i, j, graph->adj_matrix[i][j]);
                        }
                    }
                }
            }
        }
        fclose(fp);
        return 0;
    }
}
