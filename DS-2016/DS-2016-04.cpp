/*
	设计算法 求图中 从 u->v 的一条简单路径(路径上任何两点都不重复)
*/

#include <iostream>
#include<stack>
using namespace std;

// 定义图的最大顶点数
#define MaxSize 20

// 定义边结构类型
typedef struct ArcNode
{
	// 边指向定点位置
	int adjvex;
	// 指向下一条边的指针
	struct ArcNode* nextArc;
}ArcNode;

// 定义顶点结构类型
typedef struct VNode
{
	// 该顶点指向的第一边指针
	struct ArcNode* firstArc;
	// 顶点数据
	char data;
}VNode, adjList[MaxSize];


// 图的定义
typedef struct Graph
{
	// 顶点数，边数
	int vexNum, arcNum;
	// 顶点数组
	adjList vexs;
}Graph;

// 获取数据在图顶点的位置，找到返回对应下标，否则返回-1
int location(Graph* g, char v1)
{
	for (int i = 0; i < g->vexNum; ++i)
	{
		if (v1 == g->vexs[i].data)
			return i;
	}
	return -1;
}


// 创建无向图
void createGraph(Graph* g)
{
	char v1, v2;
	//cout << "顶点数，边数:";
	cin >> g->vexNum >> g->arcNum;
	for (int i = 0; i < g->vexNum; ++i)
	{
		//cout << "第 " << i + 1 << " 个顶点数据:";
		cin >> g->vexs[i].data;
		g->vexs[i].firstArc = NULL;
	}

	for (int i = 0; i < g->arcNum; ++i)
	{
		//cout << "第 " << i + 1 << " 边的两个顶点数据:";
		cin >> v1 >> v2;
		// 获取 v1 和 v2 在顶点数组中的位置
		int l1 = location(g, v1);
		int l2 = location(g, v2);
		if (l1 == -1 || l2 == -1)
		{
			cout << "输入数据不合法，创建失败！" << endl;
			return;
		}
		// 无向图构建， 头插法建立边表
		ArcNode* p = new ArcNode;
		p->adjvex = l2;
		p->nextArc = g->vexs[l1].firstArc;
		g->vexs[l1].firstArc = p;

		p = new ArcNode;
		p->adjvex = l1;
		p->nextArc = g->vexs[l2].firstArc;
		g->vexs[l2].firstArc = p;
	}
}

// DFS 遍历图
void DFS(Graph* g, int v)
{
	// 设置顶点访问标志
	static bool visit[MaxSize] = { false };
	// 访问顶点v
	cout << g->vexs[v].data << " ";
	// 标记V已访问
	visit[v] = true;
	// 获取顶点v相连接的第一条边结点
	ArcNode* p = g->vexs[v].firstArc;
	while (p)
	{
		// p指向结点未访问
		if (visit[p->adjvex] == false)
		{
			DFS(g, p->adjvex);
		}
		else
		{
			// 访问下一条边
			p = p->nextArc;
		}
	}
}


// 从u -> v 简单路径
void findSimplePath(Graph* g, int u, int v, int d)
{
	// 程序跳出递归条件
	static bool flag = false;
	if (flag == true)
		return;
	int w;
	// 设置顶点访问标志
	static bool visit[MaxSize] = { false };
	// 存储路径数组
	static int path[MaxSize] = { -1 };
	//++d;
	path[d] = u;
	// 设置当前结点已访问
	visit[u] = true;
	if (u == v)
	{
		// 从u -> v 找到简单路径
		cout << "Simple Path : ";
		for (int i = 0; i <= d; ++i)
		{
			cout << g->vexs[path[i]].data << " ";
		}
		cout << endl;
		// 找到简单路径，跳出递归
		flag = true;
		return;
	}
	for (auto p = g->vexs[u].firstArc; p; p = p->nextArc)
	{
		w = p->adjvex;
		if (visit[w] == false)
		{
			findSimplePath(g, w, v, d+1);
		}
	}
	
}

/* 测试数据
	5 6
	A
	B
	C
	D
	E
	A E
	A C
	C E
	C D
	D B
	B E
*/
int main()
{
	Graph g;
	createGraph(&g);
	DFS(&g, 0);
	cout << endl;
	findSimplePath(&g, 0, 4, 0);
	system("pause");
	return 0;
}