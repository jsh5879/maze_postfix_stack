//3.6.2 postfix notation
//3.18~19
#include <iostream>
#include <memory>
#include "stack.h"
typedef char* Expression;
typedef char Token;
using namespace std;

int index = 0;
struct token {
	bool tag;//0이면 숫자, 1이면 operator
	union {
		int num;//12+13
		char opcode[3];//+,-   unary -는 $-로 저장
	};
};
struct token inputToken[30];
char NextToken(Expression e)
{
	char ch = e[index];
	if (isOperand(ch))
	{
		inputToken[index].tag = 0;
		if (isOperand(e[index + 1])) {

			inputToken[index].num = 12; //
		}
		else
			inputToken[index].num = 1; //
	}
	else {
		inputToken[index].tag = 1;
		if (isOperand(e[index + 1])) {
			//opcode 찾는다 +, *
		}
		else
			//opcode 찾는다 <= 등에 대하여
	}


	index++;
	//수정 필요
	return token;
}

bool isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '<' ||x == '>'||
		x == '(' || x == ')' || x == '%' || x == '#')
		return false;
	else
		return true;
}

int isp(char a)
{
	if (a == '(')
		return 8;
	else if (a == '#')
		return 8;
	else if (a == '-' || a == '+' || a == '!')//unary -, unary +
		return 1;
	else if (a == '*' || a == '%' || a == '/')
		return 2;
	else if (a == '+' || a == '-')
		return 3;
	else if (a == '<' || a == '>' || a == '<=' || a == '>=')
		return 4;
	else if (a == '==' || a == '!=')
		return 5;
	else if (a == '&&')
		return 6;
	else if (a == '||')
		return 7;
	else
		return 10;
}

int icp(char a)
{
	if (a == '(')
		return 0;
	else if (a == '-' || a == '+' || a == '!')//unary -, unary +
		return 1;
	else if (a == '*' || a == '%' || a == '/')
		return 2;
	else if (a == '+' || a == '-')
		return 3;
	else if (a == '<' || a == '>'|| a == '<='||a == '>=')
		return 4;
	else if (a == '==' || a == '!=')
		return 5;
	else if (a == '&&')
		return 6;
	else if (a == '||')
		return 7;
	else
		return 10;
}

Expression Postfix(Expression e)
{
	Stack<char> stack;
	stack.Push('#');
	for (char x = NextToken(e); x != NULL; x = NextToken(e))
	{
		if (isOperand(x))
			cout << x;
		else if (x == ')')
		{
			while (stack.Top() != '(')
			{
				cout << stack.Top();
				stack.Pop();
			}
			stack.Pop();
		}
		else
		{
			for (; isp(stack.Top()) >= icp(x); stack.Pop())
				cout << stack.Top();
			stack.Push(x);
		}
	}

	char x;
	while ((x = stack.Top()) != '#')
	{
		cout << x;
		stack.Pop();
	}
	cout << endl;
}

void Eval(Expression e) {
	Stack<Token> stack;
	stack.Push('#');
	for (Token x = NextToken(e); x != '#'; x = NextToken(e))
		if (isOperand(x)) stack.Push(x);
		else {
			//remove the correct number of operands for operator x from stack;
			//perform the operation x and store the result onto the stack;
		}
}

void main()
{
	index = 0;
	Expression infix, postfix;
	scanf("%s", infix);
	cout << infix << endl;
	postfix = Postfix(infix);
	Eval(postfix);
	cout << postfix << endl;
}
