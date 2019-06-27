/*
	����㷨 ��ͼ�� �� u->v ��һ����·��(·�����κ����㶼���ظ�)
*/

#include <iostream>
#include<stack>
using namespace std;

// ����ͼ����󶥵���
#define MaxSize 20

// ����߽ṹ����
typedef struct ArcNode
{
	// ��ָ�򶨵�λ��
	int adjvex;
	// ָ����һ���ߵ�ָ��
	struct ArcNode* nextArc;
}ArcNode;

// ���嶥��ṹ����
typedef struct VNode
{
	// �ö���ָ��ĵ�һ��ָ��
	struct ArcNode* firstArc;
	// ��������
	char data;
}VNode, adjList[MaxSize];


// ͼ�Ķ���
typedef struct Graph
{
	// ������������
	int vexNum, arcNum;
	// ��������
	adjList vexs;
}Graph;

// ��ȡ������ͼ�����λ�ã��ҵ����ض�Ӧ�±꣬���򷵻�-1
int location(Graph* g, char v1)
{
	for (int i = 0; i < g->vexNum; ++i)
	{
		if (v1 == g->vexs[i].data)
			return i;
	}
	return -1;
}


// ��������ͼ
void createGraph(Graph* g)
{
	char v1, v2;
	//cout << "������������:";
	cin >> g->vexNum >> g->arcNum;
	for (int i = 0; i < g->vexNum; ++i)
	{
		//cout << "�� " << i + 1 << " ����������:";
		cin >> g->vexs[i].data;
		g->vexs[i].firstArc = NULL;
	}

	for (int i = 0; i < g->arcNum; ++i)
	{
		//cout << "�� " << i + 1 << " �ߵ�������������:";
		cin >> v1 >> v2;
		// ��ȡ v1 �� v2 �ڶ��������е�λ��
		int l1 = location(g, v1);
		int l2 = location(g, v2);
		if (l1 == -1 || l2 == -1)
		{
			cout << "�������ݲ��Ϸ�������ʧ�ܣ�" << endl;
			return;
		}
		// ����ͼ������ ͷ�巨�����߱�
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

// DFS ����ͼ
void DFS(Graph* g, int v)
{
	// ���ö�����ʱ�־
	static bool visit[MaxSize] = { false };
	// ���ʶ���v
	cout << g->vexs[v].data << " ";
	// ���V�ѷ���
	visit[v] = true;
	// ��ȡ����v�����ӵĵ�һ���߽��
	ArcNode* p = g->vexs[v].firstArc;
	while (p)
	{
		// pָ����δ����
		if (visit[p->adjvex] == false)
		{
			DFS(g, p->adjvex);
		}
		else
		{
			// ������һ����
			p = p->nextArc;
		}
	}
}


// ��u -> v ��·��
void findSimplePath(Graph* g, int u, int v, int d)
{
	// ���������ݹ�����
	static bool flag = false;
	if (flag == true)
		return;
	int w;
	// ���ö�����ʱ�־
	static bool visit[MaxSize] = { false };
	// �洢·������
	static int path[MaxSize] = { -1 };
	//++d;
	path[d] = u;
	// ���õ�ǰ����ѷ���
	visit[u] = true;
	if (u == v)
	{
		// ��u -> v �ҵ���·��
		cout << "Simple Path : ";
		for (int i = 0; i <= d; ++i)
		{
			cout << g->vexs[path[i]].data << " ";
		}
		cout << endl;
		// �ҵ���·���������ݹ�
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

/* ��������
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