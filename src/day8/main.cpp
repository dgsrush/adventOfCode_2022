#include<iostream>
#include<vector>
#include<cstring>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::endl;

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	int grid[99][99];
	memset(&grid, 0, 99*99);

	int rowcnt = 0;
	int colcnt = 0;
	for(std::string ss : ll)
	{
		colcnt = ss.length();
		for(int i = 0; i < colcnt; i++)
			grid[rowcnt][i] = std::stoi(ss.substr(i,1));
		rowcnt++;
	}

	int visible = 0;
	int score = 0;
	for(int row = 0; row < rowcnt; row++)
	{
		for(int col = 0; col < colcnt; col++)
		{
			if(row == 0 || row == (rowcnt-1))
				visible++;
			else if(col == 0 || col == (colcnt-1))
				visible++;
			else
			{
				int val = grid[row][col];
				bool ok1 = true, ok2 = true, ok3 = true, ok4 = true;
				int vcnt1 = 0, vcnt2 = 0, vcnt3 = 0, vcnt4 = 0;
				for(int i = col-1; i >= 0; i--) //left
				{
					if(grid[row][i] >= val) { ok1 = false; vcnt1++; break; }
					vcnt1++;
				}
				for(int i = col+1; i < colcnt; i++) //right
				{
					if(grid[row][i] >= val) { ok2 = false; vcnt2++; break; }
					vcnt2++;
				}
				for(int i = row-1; i >= 0; i--) //up
				{
					if(grid[i][col] >= val) { ok3 = false; vcnt3++; break; }
					vcnt3++;
				}
				for(int i = row+1; i < rowcnt; i++) //down
				{
					if(grid[i][col] >= val) { ok4 = false; vcnt4++; break; }
					vcnt4++;
				}
				if(ok1 || ok2 || ok3 || ok4) visible++;
				int vcnt = vcnt1 * vcnt2 * vcnt3 * vcnt4;
				if(vcnt > score) score = vcnt;
			}
		}
	}
	cout << "PART 1 visible = " << visible << endl;
	cout << "PART 2 score   = " << score << endl;
}

int main()
{
	calc();
	return 0;
}
