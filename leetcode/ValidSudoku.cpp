// ValidSudoku.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		if (board.empty())
			return false;
		if(checkCols(board)&&checkGrid(board)&&checkRows(board))
			return true;
		else
			return false;

	}
	bool checkRows(vector<vector<char> > &board){
		int A[10] = {0};
		for (int nRow=0;nRow<9;nRow++){
			memset(A,0,sizeof(A));
			for (int i=0;i<9;i++)
			{
				int index = board[nRow][i]-'0';
				if (index == ('.'-'0'))
					continue;
				if(A[index]<1)
					A[index] = 1;
				else
				return false;
			}
		}
		return true;
	}
	bool checkCols(vector<vector<char> > &board){
		int A[10] = {0};
		for(int nCol=0;nCol<9;nCol++){
			memset(A,0,sizeof(A));
			for(int i=0;i<9;i++){
				int index = board[i][nCol]-'0';
				if (index == ('.'-'0'))
					continue;
				if(A[index]<1)
					A[index] = 1;
				else
					return false;
			}
		}
		return true;
	}
	bool checkGrid(vector<vector<char> > &board){
		int A[10] = {0};
		for(int nGrid=0;nGrid<9;nGrid++){
			memset(A,0,sizeof(A));
			int gx = (nGrid/3+1)*3;
			int gy = (nGrid%3+1)*3;
			for (int x=gx-3; x<gx;x++){
				for (int y=gy-3;y<gy;y++){
					int index = board[x][y]-'0';
					if (index == ('.'-'0'))
						continue;
					if(A[index]<1)
						A[index] = 1;
					else
						return false;
				}
			}
		}
		return true;
	}
};

void pushChar(vector<char>  &boardc,string a,vector<vector<char> > &board){
	boardc.clear();
	for (int j=0;j<a.length();j++)
	{
		boardc.push_back(a[j]);
	}
	board.push_back(boardc);
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<char> > board;
	vector<char>  boardc ;

	pushChar(boardc,".87654321",board);
	pushChar(boardc,"2........",board);
	pushChar(boardc,"3........",board);
	pushChar(boardc,"4........",board);
	pushChar(boardc,"5........",board);
	pushChar(boardc,"6........",board);
	pushChar(boardc,"7........",board);
	pushChar(boardc,"8........",board);
	pushChar(boardc,"9........",board);

	Solution test;
	cout<<test.checkGrid(board)<<endl;
	return 0;
}

