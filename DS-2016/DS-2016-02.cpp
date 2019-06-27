/**
	�㷨���жϱ��ʽ�����ҿ��շ����Ƿ�ƥ��
*/

#include <iostream>
#include<string>
#include <stack>
using namespace std;

// ƥ���㷨���жϱ��ʽ�ַ������������Ƿ�ƥ��
bool isMatch(string str)
{
	stack<char> s;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			// �����ž���ջ
			s.push(str[i]);
			continue;
		}

		switch (str[i])
		{
		case ')':
			if (s.top() != '(')
				return false;
			s.pop();
			break;
		case ']':
			if (s.top() != '[')
				return false;
			s.pop();
			break;
		case '}':
			if (s.top() != '{')
				return false;
			s.pop();
			break;
		}
	}
	// �����ջ���գ���ƥ��ʧ��
	if (!s.empty())
		return false;

	// ����ֱ�ӷ���true
	return true;
}

int main()
{
	string str = "[a+b+c+d](({))";
	cout << (isMatch(str) == true ? "ƥ��ɹ�" : "ƥ��ʧ��") << endl;
	system("pause");
	return 0;
}