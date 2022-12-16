#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<limits>
#include<map>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::cerr;
using std::endl;

class Sensor
{
public:
	Sensor() : x(0), y(0), bx(0), by(0), dist(0) {}
	void print();
	void computeDistance();
	int x, y, bx, by;
	int dist;
};

void Sensor::computeDistance() { dist = abs(x - bx) + abs(y - by); }

void Sensor::print() { cout << x << "," << y << " = " << bx << "," << by << " dist=" << dist <<endl; }

std::vector<Sensor *> sensors;
int minx = INT_MAX;
int maxx = -INT_MAX;
int miny = INT_MAX;
int maxy = -INT_MAX;

void init()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::string delims = " =,:";
	for(std::string ss : ll)
	{
		if(ss[0] == '#') continue;
		std::vector<std::string> tkns;
		AocUtils::tokenize(ss, delims, tkns);
		Sensor *s = new Sensor();
		s->x = std::stoi(tkns[3]);
		s->y = std::stoi(tkns[5]);
		s->bx = std::stoi(tkns[11]);
		s->by = std::stoi(tkns[13]);
		sensors.push_back(s);
		s->computeDistance();
	}

	for(Sensor *s : sensors)
	{
		minx = std::min(minx, s->x);
		maxx = std::max(maxx, s->x);
		minx = std::min(minx, s->bx);
		maxx = std::max(maxx, s->bx);
		miny = std::min(miny, s->y);
		maxy = std::max(maxy, s->y);
		miny = std::min(miny, s->by);
		maxy = std::max(maxy, s->by);
	}
	//cout << minx << " " << miny << endl;
	//cout << maxx << " " << maxy << endl;
}

bool calc(int part, int yline)
{
	std::map<int, char> line10;
	for(int i = minx; i <= maxx; i++)
		line10[i] = '.';

	int yy, dd;
	int total = 0;
    for(Sensor *s : sensors)
    {
		if(s->y == yline) line10[s->x] = 'S';
		if(s->by == yline) line10[s->bx] = 'B';

		for(int i = 0; i <= s->dist; i++)
		{
			//draw up
			yy = s->y - i;
			if(yy == yline)
			{
				dd = s->dist - i;
				for(int j = 0; j <= dd; j++)
				{
					if(line10[s->x - j] == '.') { line10[s->x - j] = '#'; total++; }
					if(line10[s->x + j] == '.') { line10[s->x + j] = '#'; total++; }
				}
			}
			//draw down
			yy = s->y + i;
			if(yy == yline)
			{
				dd = s->dist - i;
				for(int j = 0; j <= dd; j++)
				{
					if(line10[s->x - j] == '.') { line10[s->x - j] = '#'; total++; }
					if(line10[s->x + j] == '.') { line10[s->x + j] = '#'; total++; }
				}
			}
		}
	}

	if(part == 1)
	{
		//print line10
    	//for(int i = minx; i <= maxx; i++)
		//  	cout << line10[i];
		//cout << endl;

		cout << "PART 1 total = " << total << endl;
	}
	else if(part == 2)
	{
		//cout << total << endl;
		if(total != 4000001)
		{
			for(int i = 0; i <= 4000000; i++)
			{
				if(line10[i] == '.')
				{
					cout << "y=" << yline << endl;
					cout << "x=" << i << endl;
					cout << "PART 2 answer = " << (4000000 * i) + yline << endl;
					return true;
				}
			}
		}
	}
	return false;
}

//PART 2 is too slow to give an answer currently
int main()
{
	init();

	//calc(1, 10);
	calc(1, 2000000);

minx = 0;
maxx = 4000000;
	for(int y = 0; y < 4000001; y++)
//	for(int y = 0; y < 21; y++)
	{
cout << y << endl;
		if(calc(2, y)) break;
	}

	for(Sensor *s : sensors)
		delete s;
	sensors.clear();

	return 0;
}
