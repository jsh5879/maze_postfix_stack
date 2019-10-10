#pragma once
const int DefaultSize = 100;

enum directions { N, NE, E, SE, S, SW, W, NW };

const int ROWS = 30, COLS = 30;
struct offsets {
	int a, b;
};
class Maze {
public:
	void randomInitialize();//boundary는 1로 설정 나머지는 0으로 설정, maze[][], mark[][]를 초기화
	int findPath(offsets& , offsets& );
	offsets getNextStart();//미로의 좌측이 0인 것을 return
	offsets getNextEnd();//미로의 우측이 0인 것을 return
	friend ostream& operator<<(ostream& stream, Maze& maze);
private:
	int maze[ROWS+1][COLS+1];//boundary는 maze[0][], maze[ROWS+1][], maze[][0], maze[][COLS+1] = 1
	int mark[ROWS][COLS];//1 ~ ROWS, 1 ~ COLS를 mark로 사용
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
		// m x n 크기의 미로를 초기화함. ( 상하좌우 1열은 구분을 위해 벽으로 만듬 )
	for (int i = 0; i < ROWS + 1; i++) {
		for (int j = 0; j < COLS + 1; j++)
		{
			// Maze의 벽 부분 처리
			if (/* 벽의 여부를 확인하는 조건식 필요/*/)
			{

			}
			// 벽이 아닐 경우 랜덤하게 생성
			else {
			};
		}
	}
	for (int i = 0; i < ROWS + 1; i++)
	{
		for (int j = 0; j < COLS + 1; j++)
		{
			// Maze의 벽 부분 처리
			if (/* 벽의 여부를 확인하는 조건식 필요*/)
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
	// 출발점을 구하는 함수 구현
	// 출발점은 미로의 가장 왼쪽에 있는 공간 중 0인 숫자만 될 수 있음.
}
offsets Maze::getNextEnd()
{
	// 도착점을 구하는 함수 구현
	// 출발점은 미로의 가장 오른쪽에 있는 공간 중 0인 숫자만 될 수 있음.
}
ostream& operator<<(ostream& stream, Maze& _maze)
{
	// Maze와 mark를 각각 출력하는 함수 구현
	return stream;
}