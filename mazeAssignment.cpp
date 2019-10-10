/* mazeAssignment,cpp - finding a path through a maze
학번:
이름:
github id:
*/
#include <iostream>
#include <fstream>
#include "stack.h"
#include "maze.h"
using namespace std;

ostream& operator<<(ostream& os, items& item)
{
	return os << item.x << "," << item.y << "," << item.dir;
}

/*
maze[][], mark[][]를 class의 private data member로 선언
main()에서는 class의 public function의 호출로 미로 찾기
*/
void main() {
	Maze* m = new Maze();
	int result, count;
	struct offsets start, end;
	do {
		m->randomInitialize();
		cout << m << endl;//난수를 사용하여 생성된 maze[][]을 출력
		count = 0; //입출구 카운터
		do {
			start = m->getNextStart(); //입구하나씩 찾는것
			end = m->getNextEnd();
			result = m->findPath(start, end);
		} while (!result && count++ < 2 * ROWS);
	} while (!result);
	cout << start << end << end << endl;
	cout << m << endl;//미로 경로는 9로 출력
}
