// 6_35_关键活动.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<utility>
using namespace std;
#define Maxsize 101
#define Inf 65535
typedef int Vertex;
typedef int WeightType;
typedef struct LNode* PtrToLNode;
typedef struct VNode {
	PtrToLNode FirstEdge;
	WeightType Earliest;
	WeightType Latest;
	int InDegree;
	VNode() :FirstEdge(NULL), Earliest(0), Latest(Inf), InDegree(0) {}
}PtrToLNodeArr[Maxsize];

struct LNode {
	Vertex V;
	WeightType Weight;
	WeightType Delay;
	PtrToLNode Next;

};
typedef struct GraphNode* Graph;
struct GraphNode {
	int Nv;
	int Ne;
	PtrToLNodeArr heads;
};

Graph BuildGraph(int N, int M) {
	Graph G = new GraphNode;
	G->Nv = N;
	G->Ne = M;
	Vertex v1, v2;
	WeightType W;
	PtrToLNode tmp;
	for (int i = 1; i <= M; i++) {
		cin >> v1 >> v2 >> W;
		tmp = new LNode;
		tmp->V = v2;
		tmp->Weight = W;
		tmp->Next = G->heads[v1].FirstEdge;
		G->heads[v1].FirstEdge = tmp;
	}
	return G;
}
/*以上为建图*/

/*拓扑排序*/

void InDegreeCount(Graph G) {
	/*统计入度*/
	PtrToLNode tmp;
	Vertex V, W;
	for (V = 1; V <= G->Nv; V++) {
		tmp = G->heads[V].FirstEdge;
		while (tmp != NULL) {
			W = tmp->V;
			G->heads[W].InDegree++;
			tmp = tmp->Next;
		}
	}
}

int TopSorting(Graph G) {
	InDegreeCount(G);
	queue<Vertex> q;
	stack<Vertex> s;
	Vertex V, W;//点对象
	int res = 0;//结果
	PtrToLNode tmp;//边对象指针
	for (Vertex V = 1; V <= G->Nv; V++) {//将入度为0的入队列
		if (G->heads[V].InDegree == 0) {
			q.push(V);
		}
	}
	int Vcount = 0;//用来统计拓扑排序是否失效
	while (q.empty() != 1) {
		V = q.front();
		s.push(V);
		q.pop();//弹出V
		Vcount++;
		for (tmp = G->heads[V].FirstEdge; tmp != NULL; tmp = tmp->Next) {//对V的邻接点进行更新
			W = tmp->V;
			G->heads[W].InDegree--;//更新入度
			if (G->heads[W].InDegree == 0) {
				q.push(W);
			}
			if (G->heads[V].Earliest + tmp->Weight > G->heads[W].Earliest) {
				G->heads[W].Earliest = G->heads[V].Earliest + tmp->Weight;//更新W的最早时间
			}
		}
	}
	/*判断拓扑排序是否失效，没有失效才继续往下做*/
	if (Vcount != G->Nv) {
		res = 0;
		return res;
	}
	InDegreeCount(G);//重新更新一下入度,可不做这一步，不影响结果

	int MaxTime = 0;
	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {//找到所有节点中的最大的时间
		MaxTime = MaxTime > G->heads[Vtmp].Earliest ? MaxTime : G->heads[Vtmp].Earliest;
	}

	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {//初始化所有节点的Latest时间为MaxTime
		G->heads[Vtmp].Latest = MaxTime;
	}

	while (s.empty() != 1) {//按照栈的顺序进行反序修改Latest
		V = s.top();
		s.pop();//反序弹出V
		for (tmp = G->heads[V].FirstEdge; tmp != NULL; tmp = tmp->Next) {
			W = tmp->V;
			if (G->heads[V].Latest > G->heads[W].Latest - tmp->Weight) {
				G->heads[V].Latest = G->heads[W].Latest - tmp->Weight;//更新V点的Latest
			}
		}
	}

	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {//对所有边对象更新Delay
		tmp = G->heads[Vtmp].FirstEdge;
		while (tmp != NULL) {
			W = tmp->V;
			tmp->Delay = G->heads[W].Latest - (G->heads[Vtmp].Earliest + tmp->Weight);//计算边<v,w>的delay
			tmp = tmp->Next;
		}
	}
	return 1;
}

int FindMaxTime(Graph G) {
	int MaxTime = 0;
	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {
		MaxTime = MaxTime > G->heads[Vtmp].Earliest ? MaxTime : G->heads[Vtmp].Earliest;
	}
	return MaxTime;
}


void DispRes(int res, Graph G) {
	if (res == 0) {
		cout << "0";
	}
	else if (res == 1) {
		int MaxTime = FindMaxTime(G);
		multimap<Vertex, PtrToLNode> path;
		PtrToLNode tmp;//边对象
		for (Vertex V = 1; V <= G->Nv; V++) {
			tmp = G->heads[V].FirstEdge;
			while (tmp != NULL) {
				if (tmp->Delay == 0) {//判断是否是关键路径
					path.insert(make_pair(V, tmp));
				}
				tmp = tmp->Next;
			}
		}
		cout << MaxTime << endl;
		for (auto pt = path.begin(); pt != path.end(); pt++) {
			cout << pt->first << "->" << pt->second->V << endl;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	Graph G = BuildGraph(N, M);
	int res;
	res = TopSorting(G);
	DispRes(res, G);
	return 0;
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
