#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<limits>
#include<map>
#include<thread>
#include"AocUtils.h"
#include"StrUtils.h"
#include"FuncPool.h"

using std::cout;
using std::cerr;
using std::endl;

class Sensor
{
public:
	Sensor() : x(0), y(0), bx(0), by(0), dist(0) {}
	void print();
	void computeDistance();
	long long x, y, bx, by;
	long long dist;
};

void Sensor::computeDistance() { dist = abs(x - bx) + abs(y - by); }

void Sensor::print() { cout << x << "," << y << " = " << bx << "," << by << " dist=" << dist <<endl; }

std::vector<Sensor *> sensors;
long long minx = LLONG_MAX;
long long maxx = LLONG_MIN;

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
	}
}

void calcPart1(long long yline)
{
	std::map<long long, char> line10;
	for(long long i = minx; i <= maxx; i++)
		line10[i] = '.';

	long long yy, dd;
	long long total = 0;
	for(Sensor *s : sensors)
	{
		if(s->y == yline) line10[s->x] = 'S';
		if(s->by == yline) line10[s->bx] = 'B';

		for(long long i = 0; i <= s->dist; i++)
		{
			//draw up
			yy = s->y - i;
			if(yy == yline)
			{
				dd = s->dist - i;
				for(long long j = 0; j <= dd; j++)
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
				for(long long j = 0; j <= dd; j++)
				{
					if(line10[s->x - j] == '.') { line10[s->x - j] = '#'; total++; }
					if(line10[s->x + j] == '.') { line10[s->x + j] = '#'; total++; }
				}
			}
		}
	}
	cout << "PART 1 total = " << total << endl;
}

void calcPart2(long long x)
{
	long long dist;
	bool fnd;
	for(long long y = 0; y < 4000000; y++)
	{
		fnd = true;
		for(Sensor *s : sensors)
		{
			if(s->x == x && s->y == y) { fnd = false; break; }
			if(s->bx == x && s->by == y) { fnd = false; break; }
			dist = abs(s->x - x) + abs(s->y - y);
			if(dist <= s->dist) { fnd = false; break; }
		}
		if(fnd)
		{
			cout << "PART 2 answer: x=" << x << " y=" << y << endl;
			cout << "PART 2 answer = " << (4000000 * x) + y << endl;
		}
	}
}

FuncPool funcPool;

void part2()
{
	std::vector<std::thread> threadPool;
	for(long long i = 0; i < 16; i++)
		threadPool.push_back(std::thread(&FuncPool::loopFunc, &funcPool));
	for(long long x = 0; x < 4000000; x++)
		funcPool.push(calcPart2, x);
	funcPool.done();
	for(long long i = 0; i < threadPool.size(); i++)
		threadPool.at(i).join();
}

int main()
{
	init();
	calcPart1(2000000);
	part2();
	for(Sensor *s : sensors)
		delete s;
	sensors.clear();
	return 0;
}

