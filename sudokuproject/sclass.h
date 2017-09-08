#pragma once
class sudoku {
private:
	int sudokuarr[9][9];//存放数独的数组；
	int row;//记录当前填到了第几行；
	int col;
	int maxcount;//最大随机阀值；
public:
	sudoku() {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				this->sudokuarr[i][j] = 0;
			}
		}
		row = 0;
		col = 0;
		maxcount = 220;
	}
	int setrand();//生成随机数；
	void getsudoku();//生成数独终盘；
	int judgerow(int temp);//对行进行判断；
	int judgecol(int temp);//对列进行判断；
	int judgeblock(int temp);//对3*3方块进行判断；
	int getrow();
	int getcol();
	void print();
};