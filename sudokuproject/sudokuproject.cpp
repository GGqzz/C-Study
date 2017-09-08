// sudokuproject.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "sclass.h"

int sudoku::getrow()
{
	return row;
}
int sudoku::getcol()
{
	return col;
}
int sudoku::judgerow(int temp)
{
	for (int j = 0; j < getcol(); j++)
	{
		if (temp ==sudokuarr[row][j] )
				return 0;
	}
	return 1;
}
int sudoku::judgecol(int temp)
{
		for (int j = 0; j < getrow(); j++)
		{
			if (temp == sudokuarr[j][col])
				return 0;
		}
	return 1;
}
int sudoku::judgeblock(int temp)
{
	int startRow = getrow() / 3 * 3;//确定当前填的数是第几个3*3方框中
	int startCol = getcol() / 3 * 3;
	for (int i = 0; i < 8; i++)
	{
		if (sudokuarr[startRow + i / 3][startCol + i % 3] == 0)
		{
			continue;
		}
		for (int j = i+1; j < 9; j++)
		{
			if (sudokuarr[startRow + i/3][startCol + j%3] == temp)
				return 0;
		}
	}
	return 1;
}

int sudoku::setrand()
{
	srand((unsigned)time(NULL));
	int temp = rand() % 9+1;
	//cout << temp << endl;
	return temp;
}
void sudoku::getsudoku()//生成数独终盘；
{
	int count=0;//产生随机数的次数；
	int temp;
	while (1)
	{
		if (col == 9 && row == 8)
		{
			break;
		}
		col = col % 9;
		if (col == 0 && row == 0)
		{
			this->sudokuarr[row][col] = setrand();
			this->col++;
			//cout << row << " " << col<<" "<<count<<" "<<maxcount << endl;
		}
		else
		{
			temp = setrand();
			if (judgeblock(temp) && judgecol(temp) && judgerow(temp))
			{
				this->sudokuarr[row][col] = temp;
				this->col++;
				if (this->col == 9)
				{
					this->row++;
				}
				cout << row << " " << col <<" "<<temp<< endl;
				count = 0;
			}
			else
			{
				count++;
			}
		}
		if (count == maxcount)//超过最大阀值重置；
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					this->sudokuarr[i][j] = 0;
				}
			}
			col = 0;
			row = 0;
			count = 0;
		}
	}
}
void sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << this->sudokuarr[i][j] << " ";
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
    return 0;
}

