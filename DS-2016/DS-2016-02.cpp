/**
	算法：判断表达式中左右开闭符号是否匹配
*/

#include <iostream>
#include<string>
#include <stack>
using namespace std;

// 匹配算法，判断表达式字符串开闭括号是否匹配
bool isMatch(string str)
{
	stack<char> s;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			// 左括号均进栈
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
	// 左符号栈不空，则匹配失败
	if (!s.empty())
		return false;

	// 否则直接返回true
	return true;
}

int main()
{
	string str = "[a+b+c+d](({))";
	cout << (isMatch(str) == true ? "匹配成功" : "匹配失败") << endl;
	system("pause");
	return 0;
}