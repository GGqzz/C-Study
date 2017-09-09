#pragma once
class sudoku {
private:
	int sudokuarr[9][9];//存放数独的数组；
	int count;
public:
	sudoku() {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				this->sudokuarr[i][j] = 0;
			}
		}
		count = 0;
	}
	void getsudoku();//生成数独终盘；
	int judgerow(int row, int col);//对行进行判断；
	int judgecol(int row, int col);//对列进行判断；
	int judgeblock(int row,int col);//对3*3方块进行判断；
	void print();
	void getrand();
	void setzero(int row);
	int judge(int row, int col);
};