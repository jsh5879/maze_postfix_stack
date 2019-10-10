/* postfix.cpp -  postfix notation 
학번:
이름:
github id:
*/

#include <iostream>
#include <memory>
#include "stack.h"
typedef char* Expression;
typedef char Token;
using namespace std;
//입력은 5 + 4 + 12 * 13 등으로 정수는 두자리만 가능, 연산자는 모두 가능
int index = 0;
struct token {
	bool tag;//0이면 숫자, 1이면 operator
	union {
		int num;//12+13
		char opcode[3];//+,-   //unary -, +는 처리하지 않는다
	};
};
struct token inputToken[30];
int NextToken(Expression e) //expression을 분석하여 inputToken[]의 index를 return
{
	int num1, num2;//num1은 10단위 숫자, num2는 1단위 숫자
	char ch = e[index];
	if (isOperand(ch))
	{
		inputToken[index].tag = 0;
		if (isOperand(e[index + 1])) {
			//'c' - 'a' => 2라는 정수를 얻을 수 있음
			inputToken[index].num = 12; //
			num1 = ((char)e[index] - '0') * 10;
			num2 = (char)e[index + 1] - '0';
			inputToken[index].num = num1 + num2; 
			num1 = 0; num2 = 0;
		}
		else
			inputToken[index].num = (char)e[index] - '0';
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
	return index;
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
	for (char x = NextToken(e); x != NULL; x = NextToken(e))//NextToken()이 정수를 return하므로 수정 필요
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
	for (Token x = NextToken(e); x != '#'; x = NextToken(e))//NextToken()이 정수를 return하므로 수정 필요
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
