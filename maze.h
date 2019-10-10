#pragma once
const int DefaultSize = 100;

enum directions { N, NE, E, SE, S, SW, W, NW };

const int ROWS = 30, COLS = 30;
struct offsets {
	int a, b;
};
class Maze {
public:
	void randomInitialize();//boundary�� 1�� ���� �������� 0���� ����, maze[][], mark[][]�� �ʱ�ȭ
	int findPath(offsets& , offsets& );
	offsets getNextStart();//�̷��� ������ 0�� ���� return
	offsets getNextEnd();//�̷��� ������ 0�� ���� return
	friend ostream& operator<<(ostream& stream, Maze& maze);
private:
	int maze[ROWS+1][COLS+1];//boundary�� maze[0][], maze[ROWS+1][], maze[][0], maze[][COLS+1] = 1
	int mark[ROWS][COLS];//1 ~ ROWS, 1 ~ COLS�� mark�� ���
	offsets moves[8];
	void eightMove();
};
void Maze::eightMove() {

	moves[N].a = -1; moves[N].b = 0;
	moves[NE].a = -1; moves[NE].b = 1;
	moves[E].a = 0; moves[E].b = 1;
	moves[SE].a = 1; moves[SE].b = 1;
	moves[S].a = 1; moves[S].b = 0;
	moves[SW].a = 1; moves[SW].b = -1;
	moves[W].a = 0; moves[W].b = -1;
	moves[NW].a = -1; moves[NW].b = -1;
}
void Maze::randomInitialize() {
//maze[0~ROWS-1][0~COLWS] <= 0
	//maze[0][0~COLWS], maze[ROWS][], maze[][0], maze[][COLS] <= 1
		// m x n ũ���� �̷θ� �ʱ�ȭ��. ( �����¿� 1���� ������ ���� ������ ���� )
	for (int i = 0; i < ROWS + 1; i++) {
		for (int j = 0; j < COLS + 1; j++)
		{
			// Maze�� �� �κ� ó��
			if (/* ���� ���θ� Ȯ���ϴ� ���ǽ� �ʿ�/*/)
			{

			}
			// ���� �ƴ� ��� �����ϰ� ����
			else {
			};
		}
	}
	for (int i = 0; i < ROWS + 1; i++)
	{
		for (int j = 0; j < COLS + 1; j++)
		{
			// Maze�� �� �κ� ó��
			if (/* ���� ���θ� Ȯ���ϴ� ���ǽ� �ʿ�*/)
			{

			}
			else
			{

			}
		}
	}
}
int Maze::findPath(offsets &start, offsets &end) {
//void path(int m, int p)
// Output a path (if any) in the maze; rows is m, cols is p;
{
	//start at (1,1)
	mark[start.a][start.b] = 1;
	Stack<items> stack(ROWS * COLS);
	items temp;
	temp.x = start.a; temp.y = start.b; temp.dir = E;
	stack.Push(temp);

	while (!stack.IsEmpty()) // stack not empty
	{
		temp = stack.Pop(); // unstack
		int i = temp.x; int j = temp.y; int d = temp.dir;
		while (d < 8) // moves forward
		{
			//outFile << i << " " << j << " " << d << endl;
			int g = i + moves[d].a;
			int h = j + moves[d].b;
			if ((g == end.a) && (h == end.b)) { // reached exit
										// output path
				cout << stack;

				cout << "the term near the exit: " << i << " " << j << endl;
				cout << "exit: " << end.a << " " << end.b << endl;
				return 1;
			}
			if ((!maze[g][h]) && (!mark[g][h])) { // new position
				mark[g][h] = 1;
				//push the old temp to the stack, but the direction changes.
				//Because the neighbor in the direction of d has been checked.
				temp.x = i;  temp.y = j; temp.dir = d + 1;
				stack.Push(temp); // stack it
				i = g; j = h; d = N; // moves to (g,h)
			}
			else d++; // try next direction
		}
	}
	cout << "no path in maze " << endl;
	return 0;
}
offsets Maze::getNextStart()
{
	// ������� ���ϴ� �Լ� ����
	// ������� �̷��� ���� ���ʿ� �ִ� ���� �� 0�� ���ڸ� �� �� ����.
}
offsets Maze::getNextEnd()
{
	// �������� ���ϴ� �Լ� ����
	// ������� �̷��� ���� �����ʿ� �ִ� ���� �� 0�� ���ڸ� �� �� ����.
}
ostream& operator<<(ostream& stream, Maze& _maze)
{
	// Maze�� mark�� ���� ����ϴ� �Լ� ����
	return stream;
}