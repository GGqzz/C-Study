#pragma once
class sudoku {
private:
	int sudokuarr[9][9];//������������飻
	int row;//��¼��ǰ��˵ڼ��У�
	int col;
	int maxcount;//��������ֵ��
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
	int setrand();//�����������
	void getsudoku();//�����������̣�
	int judgerow(int temp);//���н����жϣ�
	int judgecol(int temp);//���н����жϣ�
	int judgeblock(int temp);//��3*3��������жϣ�
	int getrow();
	int getcol();
	void print();
};