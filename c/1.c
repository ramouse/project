#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define INF 32767

// 定义邻接矩阵图结构
typedef struct
{
    int arcs[MAX_VERTICES + 1][MAX_VERTICES + 1]; // 顶点编号从1开始
    int vexnum;                                   // 顶点数
    int arcnum;                                   // 边数
    int is_directed;                              // 0为无向图，1为有向图
} MGraph;

// 打印邻接矩阵
void PrintMatrix(MGraph G)
{
    printf("\n你输入的%s图的邻接矩阵表示为:\n", G.is_directed ? "有向带权" : "无向带权");
    for (int i = 1; i <= G.vexnum; i++)
    {
        for (int j = 1; j <= G.vexnum; j++)
        {
            if (G.arcs[i][j] == INF)
            {
                printf("%6s", "∞"); // 或根据截图显示 32767
            }
            else
            {
                printf("%6d", G.arcs[i][j]);
            }
        }
        printf("\n");
    }
}

// 递归打印路径
void PrintPath(int path[], int v, int source)
{
    if (v == source)
    {
        printf("%d", source);
        return;
    }
    if (path[v] == -1)
        return; // 不可达
    PrintPath(path, path[v], source);
    printf("-->%d", v);
}

// Dijkstra算法实现
void Dijkstra(MGraph G, int source)
{
    int dist[MAX_VERTICES + 1];
    int path[MAX_VERTICES + 1];
    int S[MAX_VERTICES + 1]; // 标记是否找到最短路径

    // 初始化
    for (int i = 1; i <= G.vexnum; i++)
    {
        dist[i] = G.arcs[source][i];
        S[i] = 0;
        if (G.arcs[source][i] < INF && i != source)
        {
            path[i] = source;
        }
        else
        {
            path[i] = -1;
        }
    }

    dist[source] = 0;
    S[source] = 1;
    path[source] = -1;

    // 循环 n-1 次
    for (int i = 1; i < G.vexnum; i++)
    {
        int min_dist = INF;
        int u = source;

        // 找当前不在S集合中且距离源点最近的顶点 u
        for (int j = 1; j <= G.vexnum; j++)
        {
            if (!S[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                u = j;
            }
        }

        S[u] = 1; // 将 u 加入 S 集合

        // 更新其他顶点的距离
        for (int j = 1; j <= G.vexnum; j++)
        {
            if (!S[j] && G.arcs[u][j] < INF)
            {
                if (dist[u] + G.arcs[u][j] < dist[j])
                {
                    dist[j] = dist[u] + G.arcs[u][j];
                    path[j] = u;
                }
            }
        }
    }

    // 打印结果
    printf("\n");
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (i != source)
        {
            if (dist[i] == INF)
            {
                printf("顶点%d到顶点%d不可达\n", source, i);
            }
            else
            {
                printf("顶点%d到顶点%d的最短路径长度:%d,最短路径:", source, i, dist[i]);
                PrintPath(path, i, source);
                printf("\n");
            }
        }
    }
}

int main()
{
    MGraph G;
    printf("------------------Dijkstra算法------------------\n");
    printf("请输入图的顶点个数:");
    scanf("%d", &G.vexnum);
    printf("请输入图中边的条数:");
    scanf("%d", &G.arcnum);
    printf("请选择是有向图还是无向图(有向图为1，无向图为0):");
    scanf("%d", &G.is_directed);
    printf("\n");

    // 初始化矩阵
    for (int i = 1; i <= G.vexnum; i++)
    {
        for (int j = 1; j <= G.vexnum; j++)
        {
            if (i == j)
                G.arcs[i][j] = 0; // 截图1中对角线似乎是无穷，这里按照图论规范，自己到自己可为无穷或0。根据截图2输出无穷，我们设为INF
            G.arcs[i][j] = INF;
        }
    }

    // 读入边
    int u, v, w;
    for (int i = 1; i <= G.arcnum; i++)
    {
        printf("输入第%d条边的顶点和权值(格式:u v w):", i);
        scanf("%d %d %d", &u, &v, &w);
        G.arcs[u][v] = w;
        if (G.is_directed == 0)
        {
            G.arcs[v][u] = w;
        }
    }

    PrintMatrix(G);

    int source;
    printf("请输入源点:");
    scanf("%d", &source);

    Dijkstra(G, source);

    return 0;
}