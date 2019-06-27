// DS-2016.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 删除单链表中重复元素， 并释放删除元素结点空间(试卷中单链表为非递减排列， 以下算法不要求单链表有序)

#include<iostream>
#include<string>
using namespace std;


// 链表结点类型定义
typedef struct LNode {
	// 链表指针域,指向下一结点
	struct LNode* next;
	// 链表数据域
	char data;
}LNode, *LinkList;


// 尾插法创建单链表
// L: 单链表头指针
// datas: 待插入数据
void createLinkList(LinkList &L, const string str)
{	// TODO
	L = new LNode;
	LNode* p = L;
	for (int i = 0; i < str.length(); ++i)
	{
		LNode* q = new LNode;
		q->data = str[i];
		p->next = q;
		p = q;
	}
	p->next = NULL;
}

// 删除单链表中相同元素
// q指向待判断结点，每次均与q之前未重复结点元素逐一比较，若重复则删除，否则，加入不重复序列，并更新q的指向
void removeSame(LinkList& L)
{
	// TODO
	LinkList p = L, q = p->next;
	while (q)
	{
		// 从首元结点开始查找，直到q为止
		LNode* r = L->next;
		for (; r != q; r = r->next)
		{
			if (q->data == r->data)
			{
				// q指向结点已存在
				break;
			}
		}

		// for循环正常结束， q 在之前序列未出现
		if (r == q)
		{
			// q指向结点不存在
			// 更新 p q
			p = q;
			q = q->next;
		}
		else
		{
			// 提前跳出循环，说明之前序列q已存在，则删除q指向元素结点
			// 更新p
			p->next = q->next;
			// 释放q指向结点空间
			delete q;
			// 更新q
			q = p->next;
		}
	}
}

// 输出单链表数据
void printLinkList(LinkList L)
{
	// TODO
	for (LNode* p = L->next; p; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}


int main()
{
	LinkList L;
	// 定义插入数据
	string str = "abcdefaebhijka";
	createLinkList(L, str);
	cout << "\n删除前:";
	printLinkList(L);
	cout << "\n删除后:";
	removeSame(L);
	printLinkList(L);
	system("pause");
	return 0;
}
