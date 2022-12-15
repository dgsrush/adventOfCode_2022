#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::cerr;
using std::endl;

char grid[200][1000]; // y,x
int minx = INT_MAX;
int maxx = -INT_MAX;
int miny = INT_MAX;
int maxy = -INT_MAX;

void printGrid()
{
	for(int y = 0; y < (maxy + 3); y++)
	{
		for(int x = 0; x < 1000; x++)
			cerr << grid[y][x];
		cerr << endl;
	}
	cerr << endl;
}

void drawLine(int x1, int y1, int x2, int y2)
{
	if(x1 > x2) { int t = x1; x1 = x2; x2 = t; }
	if(y1 > y2) { int t = y1; y1 = y2; y2 = t; }
	for(int y = y1; y <= y2; y++)
	{
		for(int x = x1; x <= x2; x++)
			grid[y][x] = '#';
	}
}

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::string DELIMS = "->, ";
	memset(grid, '.', 1000 * 200);

	for(std::string ss : ll)
	{
		std::vector<int> tkns;
		AocUtils::tokenize(ss, DELIMS, tkns);
		int cnt = tkns.size();
		int lx = -1, ly = -1;
		for(int i = 0; i < cnt; i += 2)
		{
			int x = tkns[i];
			int y = tkns[i+1];
			minx = std::min(minx, x);
			maxx = std::max(maxx, x);
			miny = std::min(miny, y);
			maxy = std::max(maxy, y);
			if(lx > 0)
				drawLine(x, y, lx, ly);
			lx = x; ly = y;
		}
	}

	drawLine(0, maxy + 2, 999, maxy + 2);
	//printGrid();

	int total1 = 0;
	int total2 = 0;
	bool p1done = false;
	bool done = false;
	while(!done)
	{
		int sndx = 500, sndy = 0;
		while(true)
		{
			if(grid[sndy + 1][sndx] == '.')
				sndy++;
			else if(grid[sndy + 1][sndx - 1] == '.')
			{
				sndy++;
				sndx--;
			}
			else if(grid[sndy + 1][sndx + 1] == '.')
			{
				sndy++;
				sndx++;
			}
			else
			{
				grid[sndy][sndx] = 'O';
				if(sndy > maxy)
					p1done = true;
				else if(!p1done)
					total1++;
				total2++;
				if(sndy == 0 && sndx == 500)
					done = true;
				break;
			}
		}
	}
	printGrid();
	cout << "PART 1 total = " << total1 << endl;
	cout << "PART 2 total = " << total2 << endl;
}

int main()
{
	calc();
	return 0;
}
