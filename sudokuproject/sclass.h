#pragma once
class sudoku {
private:
	int sudokuarr[9][9];//������������飻
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
	void getsudoku();//�����������̣�
	int judgerow(int row, int col);//���н����жϣ�
	int judgecol(int row, int col);//���н����жϣ�
	int judgeblock(int row,int col);//��3*3��������жϣ�
	void print();
	void getrand();
	void setzero(int row);
	int judge(int row, int col);
};