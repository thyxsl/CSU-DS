/*
	给定二叉树T， 设计算法复制拷贝二叉树T1
*/

#include <iostream>
#include<stack>
using namespace std;

// 二叉树结点类型定义
typedef struct BTNode {
	// 指向二叉树左孩子指针
	struct BTNode* lchild;
	// 指向二叉树右孩子指针
	struct BTNode* rchild;
	// 二叉树结点数据域
	char data;
}BTNode, * BiTree;


// 递归创建二叉树， 规定：输入'#'代表该结点为NULL
void createBiTree(BiTree &T)
{
	char data;
	cout << "data:";
	cin >> data;
	if (data == '#')
	{
		T = NULL;
		return;
	}
	// 创建结点T
	T = new BTNode;
	// T指针域赋值
	T->data = data;
	// 递归创建左子树
	createBiTree(T->lchild);
	// 递归创建右子树
	createBiTree(T->rchild);
}


// 中序非递归遍历二叉树
void postTraverse(BiTree T)
{	// 定义存储栈
	stack<BiTree> s;
	BTNode* p = T;
	while (!s.empty() || p)
	{
		// 栈不为空 或者p存在时执行下列操作
		if (p)
		{
			// p存在
			// p压栈
			s.push(p);
			// p指向p的左孩子
			p = p->lchild;
		}
		else 
		{
			// p不存在， 则出栈
			// 获取栈顶元素
			p = s.top();
			// 出栈
			s.pop();
			// 遍历p
			cout << p->data << " ";
			// p指向p的右孩子
			p = p->rchild;
		}
		
	}
	cout << endl;
}

// 讲二叉树T1 拷贝至 二叉树T2
void copyBiTree(BiTree T1, BiTree& T2)
{
	if (!T1)
	{
		// T1 为NULL，设置T2为NULL，并返回
		T2 = NULL;
		return;
	}

	// 为T2结点分配空间
	T2 = new BTNode;
	// 设置T2结点数据域
	T2->data = T1->data;
	// 递归创建T2左子树
	copyBiTree(T1->lchild, T2->lchild);
	// 递归创建T2右子树
	copyBiTree(T1->rchild, T2->rchild);
}

int main()
{
	BiTree T1, T2;
	createBiTree(T1);
	postTraverse(T1);
	copyBiTree(T1, T2);
	postTraverse(T2);
	system("pause");
	return 0;
}