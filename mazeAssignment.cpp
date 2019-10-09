//3.5 a mazing problem
//program 3.15: finding a path through a maze
// 3.16~17
#include <iostream>
#include <fstream>
#include "stack.h"
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



	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 17; j++)
		{
			if ((!i) || (!j) || (i == 13) || (j == 16))
				maze[i][j] = 1;
			else {
				maze[i][j] = input[i - 1][j - 1];
			};
			mark[i][j] = 0;

		}
	}
	for (int i = 0; i <= 13; i++)
	{
		for (int j = 0; j <= 16; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
	path(12, 15);

	int end;
	cin >> end;
}
