/* postfix.cpp -  postfix notation 
�й�: 201524561
�̸�: �弮ȯ
github id: jsh5879
*/

#include <iostream>
#include <memory>
#include "stack.h"
typedef char* Expression;
typedef char Token;
using namespace std;
//�Է��� 5 + 4 + 12 * 13 ������ ������ ���ڸ��� ����, �����ڴ� ��� ����

bool isOperand(char x);

int index = 0;
struct token {
	bool tag;//0�̸� ����, 1�̸� operator
	union {
		int num;//12+13
		char opcode[3];//+,-   //unary -, +�� ó������ �ʴ´�
	};
};
struct token inputToken[30];
int NextToken(Expression e) //expression�� �м��Ͽ� inputToken[]�� index�� return
{
	int num1, num2;//num1�� 10���� ����, num2�� 1���� ����
	char ch = e[index];
	if (isOperand(ch))
	{
		inputToken[index].tag = 0; //���ڴ�
		if (isOperand(e[index + 1])) { //���ڸ������ϰ��
			//'c' - 'a' => 2��� ������ ���� �� ����
			inputToken[index].num = 12;
			num1 = ((char)e[index] - '0') * 10;
			num2 = (char)e[index + 1] - '0';
			inputToken[index].num = num1 + num2; 
			num1 = 0; num2 = 0;
		}
		else //���ڸ�����
			inputToken[index].num = (char)e[index] - '0';
	}
	else {
		inputToken[index].tag = 1; //�����ڴ�
		if (isOperand(e[index + 1])) {
			//opcode ã�´� +, *
			inputToken[index].opcode[0] = e[index];
			inputToken[index].opcode[1] = NULL;
		}
		else {
			//opcode ã�´� <= � ���Ͽ�
			inputToken[index].opcode[0] = e[index];
			inputToken[index].opcode[1] = e[index + 1];
			inputToken[index].opcode[2] = NULL;
			index++;
		}
	}
	int realIndex = index;
	index++;
	//���� �ʿ�
	return realIndex;
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
	//else if (a == ')')
		//return 8;
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
	int postfixIndex = 0;
	Stack<char> stack;
	stack.Push('#');
	Expression postfix;
	char x;
	//for (char x = NextToken(e); x != NULL; x = NextToken(e))//NextToken()�� ������ return�ϹǷ� ���� �ʿ�
	for( x = e[NextToken(e)]; x != NULL; x = e[NextToken(e)])
	{
		if (isOperand(x)) {
			cout << x;
			postfix[postfixIndex] = x;
			postfixIndex++;
		}
		else if (x == ')')
		{
			while (stack.Top() != '(')
			{
				cout << stack.Top();
				postfix[postfixIndex] = x;
				postfixIndex++;
				stack.Pop();
			}
			stack.Pop();
		}
		else
		{/*
			for (; isp(stack.Top()) >= icp(x); stack.Pop())
				cout << stack.Top();
			stack.Push(x);*/
			while (isp(stack.Top()) <= icp(x)) {
				cout << stack.Top();
				postfix[postfixIndex] = x;
				postfixIndex++;
				stack.Pop();
			}
			stack.Push(x);
		}
	}

	while (stack.Top() != '#')
	{
		cout << stack.Top();
		postfix[postfixIndex] = x;
		postfixIndex++;
		stack.Pop();
	}
	stack.Pop();
	cout << "postfix: " << postfix <<endl;
}

void Eval(Expression e) {
	Stack<Token> stack;
	stack.Push('#');
	for (Token x = NextToken(e); x != '#'; x = NextToken(e))//NextToken()�� ������ return�ϹǷ� ���� �ʿ�
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
