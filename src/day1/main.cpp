#include"ReadFile.h"
#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;

void readInput(std::vector<int> *v)
{
	mhr::ReadFile inf("input.txt");
	std::string ll;
	while(inf.readLine(ll))
	{
		if(ll.length() > 0)
		{
			int ii = std::stoi(ll);
			v->push_back(ii);
		}
		else
			v->push_back(-1);
	}
	inf.close();
	v->push_back(-1);
}

void part1()
{
	std::vector<int> ll;
	readInput(&ll);
	int cnt = ll.size() - 1;

	int maxcal = 0;
	int cal = 0;
	for(int i = 0; i < cnt; i++)
	{
		if(ll[i] >= 0)
			cal += ll[i];
		else
		{
			if(cal > maxcal) maxcal = cal;
			cal = 0;
		}
	}
	cout << "PART 1 maxcal = " << maxcal << endl;
}

void part2()
{
	std::vector<int> ll;
	readInput(&ll);
	int cnt = ll.size() - 1;

	std::vector<int> totals;

	int cal = 0;
	for(int i = 0; i < cnt; i++)
	{
		if(ll[i] >= 0)
			cal += ll[i];
		else
		{
			totals.push_back(cal);
			cal = 0;
		}
	}
	std::sort(totals.begin(), totals.end());
	int total = totals[totals.size() - 3] + totals[totals.size() - 2] + totals[totals.size() - 1];
	cout << "PART 2 total = " << total << endl;
}

int main()
{
	part1();
	part2();
	return 0;
}
