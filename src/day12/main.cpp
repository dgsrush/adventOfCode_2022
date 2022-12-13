#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::endl;

class Cell
{
public:
	Cell() : row(0), col(0), cv(0), c(' '), cnt(0) {}
	void setRowCol(int rr, int cc) { row = rr; col = cc; }
	void setC(char);
	std::string getHash() { return mhr::StrUtils::to_string(row) + ":" + mhr::StrUtils::to_string(col); }
	int row, col, cv;
	char c;
	int cnt;
};

void Cell::setC(char cc)
{
	c = cc;
	if(c == 'S') c = 'a';
	else if(c == 'E') c = 'z';
	cv = c - 96;
}

int rowcnt = 0;
int colcnt = 0;
Cell grid[99][99];

Cell * getCell(int row, int col)
{
	if(row < 0 || row >= rowcnt) return NULL;
	if(col < 0 || col >= colcnt) return NULL;
	Cell *ret = NULL;
	try
	{
		ret = &grid[row][col];
	}
	catch(...) { ret = NULL; }
	return ret;
}

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	Cell *start = NULL;
	Cell *end = NULL;
	for(std::string ss : ll)
	{
		colcnt = ss.length();
		for(int i = 0; i < colcnt; i++)
		{
			grid[rowcnt][i].setRowCol(rowcnt, i);
			grid[rowcnt][i].setC(ss[i]);
			if(ss[i] == 'S') start = &grid[rowcnt][i];
			else if(ss[i] == 'E') end = &grid[rowcnt][i];
		}
		rowcnt++;
	}

	std::set<std::string> done;
	std::vector<Cell *> path;
	end->cnt = 0;
	path.push_back(end);
	done.insert(end->getHash());

	int mina = 999;
	bool loop = true;
	while(loop)
	{
		int pcnt = path.size();
		for(int i = 0; i < pcnt; i++)
		{
			Cell *cur = path[i];
			Cell *left = getCell(cur->row, cur->col-1);
			Cell *right = getCell(cur->row, cur->col+1);
			Cell *up = getCell(cur->row-1, cur->col);
			Cell *down = getCell(cur->row+1, cur->col);

			if(left != NULL && done.count(left->getHash()) == 0 && (left->cv + 1) >= cur->cv)
			{
				left->cnt = cur->cnt + 1;
				path.push_back(left);
				done.insert(left->getHash());
				if(left->c == 'a') mina = std::min(mina, left->cnt);
			}
			if(right != NULL && done.count(right->getHash()) == 0 && (right->cv + 1) >= cur->cv)
			{
				right->cnt = cur->cnt + 1;
				path.push_back(right);
				done.insert(right->getHash());
				if(right->c == 'a') mina = std::min(mina, right->cnt);
			}
			if(up != NULL && done.count(up->getHash()) == 0 && (up->cv + 1) >= cur->cv)
			{
				up->cnt = cur->cnt + 1;
				path.push_back(up);
				done.insert(up->getHash());
				if(up->c == 'a') mina = std::min(mina, up->cnt);
			}
			if(down != NULL && done.count(down->getHash()) == 0 && (down->cv + 1) >= cur->cv)
			{
				down->cnt = cur->cnt + 1;
				path.push_back(down);
				done.insert(down->getHash());
				if(down->c == 'a') mina = std::min(mina, down->cnt);
			}
			if(left == start || right == start || up == start || down == start)
			{
				loop = false;
				break;
			}
		}
	}
	cout << "PART 1 steps = " << start->cnt << endl;
	cout << "PART 2 mina  = " << mina << endl;
}

int main()
{
	calc();
	return 0;
}
