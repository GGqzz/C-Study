// sudokuproject.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "sclass.h"
int randomarr[9] = { 0 };
int sudoku::judgerow(int row, int col)
{
	int t=sudokuarr[row][col];
	for (int i = 0; i < col; i++)
	{	
		
		if (t == sudokuarr[row][i])
		{
			return 0;
		}
	}
	return 1;
}
int sudoku::judgecol(int row,int col)
{
	int t=sudokuarr[row][col];
	for (int i = 0; i < row; i++)
	{

		if (t == sudokuarr[i][col])
		{
			return 0;
		}
	}
	return 1;
}
int sudoku::judgeblock(int row,int col)
{
	int startRow = row / 3 * 3;
	int startCol = col / 3 * 3;
	for (int i = 0; i < 8; i++)
	{
		if (sudokuarr[startRow + i / 3][startCol + i % 3] == 0)
		{
			continue;
		}
		for ( int j = i+1; j < 9; j++)
		{
			if (sudokuarr[startRow + i / 3][startCol + i % 3] == sudokuarr[startRow + j / 3][startCol + j % 3])
				return 0;
		}
	}
	return 1;
}

void sudoku::getrand()
{
	int randomrang[] = { 1,2,3,4,5,6,7,8,9 };
	random_shuffle(randomrang, randomrang+9);
	for (int i = 0; i < 9; i++)
	{
		randomarr[i] = randomrang[i];
		//cout << randomrang[i] << " ";
	}
	count++;
	//cout << endl;
}
void sudoku::setzero(int row)
{
	for (int j = 0; j < 9; j++)
	{
		sudokuarr[row][j] = 0;
	}
}
int sudoku::judge(int row, int col)
{
	for (int i = 0; i < 9; i++)
	{
		sudokuarr[row][col] = randomarr[i];
		if ((judgeblock(row, col) && judgecol(row, col) && judgerow(row, col)))
		{
			return 1;
		}
	}
	return 0;
}
void sudoku::getsudoku()//生成数独终盘；
{

	int maxcount = 220;
	int row = 0;
	int col = 0;
	for (row = 0; row < 9; row++)
	{
		if (row == 0)
		{	
			getrand();
			count = 0;
			for (int i = 0; i < 9; i++)
			{
				sudokuarr[row][i] = randomarr[i];
			}
		}
		else
		{
			getrand();
			for (col = 0; col < 9; col++)
			{
				if (count < maxcount)
				{
					if (!judge(row, col))
					{
						setzero(row);
						row--;
						col = 8;
						getrand();
					}
					//cout << count << " " << row << " " << col << endl;
				}
				else
				{
					row = -1;
					col = 8;
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							sudokuarr[i][j] = 0;
						}
					}
					count = 0;
				}
			}
		}
	}
}

void sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudokuarr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "********************************" << endl;
}
int main()
{
	int n;
	cin >> n;
	sudoku sudo;
	for (int i = 0; i < n; i++)
	{
		
		sudo.getsudoku();

		sudo.print();
	}
	cin >> n;
    return 0;
}

