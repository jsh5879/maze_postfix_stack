/* mazeAssignment,cpp - finding a path through a maze
�й�:
�̸�:
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
maze[][], mark[][]�� class�� private data member�� ����
main()������ class�� public function�� ȣ��� �̷� ã��
*/
void main() {
	Maze* m = new Maze();
	int result, count;
	struct offsets start, end;
	do {
		m->randomInitialize();
		cout << m << endl;//������ ����Ͽ� ������ maze[][]�� ���
		count = 0; //���ⱸ ī����
		do {
			start = m->getNextStart(); //�Ա��ϳ��� ã�°�
			end = m->getNextEnd();
			result = m->findPath(start, end);
		} while (!result && count++ < 2 * ROWS);
	} while (!result);
	cout << start << end << end << endl;
	cout << m << endl;//�̷� ��δ� 9�� ���
}
