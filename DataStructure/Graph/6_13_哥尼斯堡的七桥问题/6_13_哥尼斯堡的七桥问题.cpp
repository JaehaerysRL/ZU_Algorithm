// 6_13_哥尼斯堡的七桥问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

/* 图的邻接矩阵表示法 */
#define MaxVertexNum 1000    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */
/* 边的定义 */
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
};
typedef PtrToENode Edge;
/* 图结点的定义 */
typedef struct MGNode* PtrToMGNode;
struct MGNode {
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
	int Degree[MaxVertexNum];
};
typedef PtrToMGNode MGraph; /* 以邻接矩阵存储的图类型 */
bool Visited[MaxVertexNum] = { false };

MGraph CreateMGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildMGraph();
void DFS(MGraph Graph, Vertex S);
bool CheckG(MGraph Graph);

int main()
{
	Vertex V;
	MGraph G = BuildMGraph();
	DFS(G, 0);
	for (V = 0; V < G->Nv; V++)
		if (!Visited[V]) break;
	if (V < G->Nv || !CheckG(G)) cout << 0 << endl;
	else cout << 1 << endl;
}

MGraph CreateMGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct MGNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++) {
		Graph->Degree[V] = 0;
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	}

	return Graph;
}
void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = 1;
	Graph->Degree[E->V1]++;
	/* 若是无向图，还要插入边<V2, V1> */
	Graph->G[E->V2][E->V1] = 1;
	Graph->Degree[E->V2]++;
}
MGraph BuildMGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i;

	scanf_s("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateMGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf_s("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
		/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i < Graph->Ne; i++) {
			scanf_s("%d %d", &E->V1, &E->V2);
			E->V1--; E->V2--; /* 输入编号从1开始 */
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}
void DFS(MGraph Graph, Vertex S) 
{
	Vertex W;

	Visited[S] = true; /* 标记S已访问 */
	for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
		/* 若W是V的邻接点并且未访问过 */
		if (!Visited[W] && IsEdge(Graph, S, W))
			DFS(Graph, W);
}
bool CheckG(MGraph Graph) 
{
	Vertex W;
	for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
		/* 若W是V的邻接点并且未访问过 */
		if (Graph->Degree[W] % 2) return false;
	return true;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
