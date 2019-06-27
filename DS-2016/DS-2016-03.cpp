/*
	����������T�� ����㷨���ƿ���������T1
*/

#include <iostream>
#include<stack>
using namespace std;

// ������������Ͷ���
typedef struct BTNode {
	// ָ�����������ָ��
	struct BTNode* lchild;
	// ָ��������Һ���ָ��
	struct BTNode* rchild;
	// ���������������
	char data;
}BTNode, * BiTree;


// �ݹ鴴���������� �涨������'#'����ý��ΪNULL
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
	// �������T
	T = new BTNode;
	// Tָ����ֵ
	T->data = data;
	// �ݹ鴴��������
	createBiTree(T->lchild);
	// �ݹ鴴��������
	createBiTree(T->rchild);
}


// ����ǵݹ����������
void postTraverse(BiTree T)
{	// ����洢ջ
	stack<BiTree> s;
	BTNode* p = T;
	while (!s.empty() || p)
	{
		// ջ��Ϊ�� ����p����ʱִ�����в���
		if (p)
		{
			// p����
			// pѹջ
			s.push(p);
			// pָ��p������
			p = p->lchild;
		}
		else 
		{
			// p�����ڣ� ���ջ
			// ��ȡջ��Ԫ��
			p = s.top();
			// ��ջ
			s.pop();
			// ����p
			cout << p->data << " ";
			// pָ��p���Һ���
			p = p->rchild;
		}
		
	}
	cout << endl;
}

// ��������T1 ������ ������T2
void copyBiTree(BiTree T1, BiTree& T2)
{
	if (!T1)
	{
		// T1 ΪNULL������T2ΪNULL��������
		T2 = NULL;
		return;
	}

	// ΪT2������ռ�
	T2 = new BTNode;
	// ����T2���������
	T2->data = T1->data;
	// �ݹ鴴��T2������
	copyBiTree(T1->lchild, T2->lchild);
	// �ݹ鴴��T2������
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