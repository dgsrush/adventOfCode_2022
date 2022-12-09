#include<iostream>
#include<string>
#include<array>
#include<unordered_set>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::endl;

class pos
{
  public:
  	pos() { x = 100; y = 100; }
  	std::string getHash() { return mhr::StrUtils::to_string(x) + ":" + mhr::StrUtils::to_string(y); }
  	bool isClose(const pos &);
  	void print() { cout << x << "x" << y << endl; }
  	int x, y;
};

bool pos::isClose(const pos &p)
{
	if(p.x == (x-1) && p.y == y) return true;
	if(p.x == (x+1) && p.y == y) return true;
	if(p.y == (y-1) && p.x == x) return true;
	if(p.y == (y+1) && p.x == x) return true;
	if(p.y == (y-1) && p.x == (x-1)) return true;
	if(p.y == (y-1) && p.x == (x+1)) return true;
	if(p.y == (y+1) && p.x == (x-1)) return true;
	if(p.y == (y+1) && p.x == (x+1)) return true;
	return false;
}

void part1()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input1.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::string SPACE = " ";
	pos head, tail;
	std::unordered_set<std::string> visited;
	visited.insert(tail.getHash());

	for(std::string ss : ll)
	{
		std::vector<std::string> tkns;
		AocUtils::tokenize(ss, SPACE, tkns);
		std::string dir = tkns[0];
		int cnt = std::stoi(tkns[1]);

		for(int i = 0; i < cnt; i++)
		{
			if(dir == "U") head.y--;
			else if(dir == "D") head.y++;
			else if(dir == "L") head.x--;
			else if(dir == "R") head.x++;

			if(!tail.isClose(head))
			{
				if((head.x + 2) == tail.x && head.y == tail.y) tail.x--;
				else if((head.x - 2) == tail.x && head.y == tail.y) tail.x++;
				else if((head.y + 2) == tail.y && head.x == tail.x) tail.y--;
				else if((head.y - 2) == tail.y && head.x == tail.x) tail.y++;
				else
				{
					if(tail.x < head.x && tail.y < head.y) { tail.x++; tail.y++; }
					else if(tail.x > head.x && tail.y > head.y) { tail.x--; tail.y--; }
					else if(tail.x > head.x && tail.y < head.y) { tail.x--; tail.y++; }
					else if(tail.x < head.x && tail.y > head.y) { tail.x++; tail.y--; }
				}
				visited.insert(tail.getHash());
			}
		}
	}
	cout << "PART 1 visited = " << visited.size() << endl;
}

void part2()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input2.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::string SPACE = " ";
	std::array<pos,10> knots;
	std::unordered_set<std::string> visited;
	visited.insert(knots[9].getHash());

	for(std::string ss : ll)
	{
		std::vector<std::string> tkns;
		AocUtils::tokenize(ss, SPACE, tkns);
		std::string dir = tkns[0];
		int cnt = std::stoi(tkns[1]);

		for(int j = 0; j < cnt; j++)
		{
			if(dir == "U") knots[0].y--;
			else if(dir == "D") knots[0].y++;
			else if(dir == "L") knots[0].x--;
			else if(dir == "R") knots[0].x++;

			for(int i = 1; i < 10; i++)
			{
				if(!knots[i].isClose(knots[i-1]))
				{
					if((knots[i-1].x + 2) == knots[i].x && knots[i-1].y == knots[i].y) knots[i].x--;
					else if((knots[i-1].x - 2) == knots[i].x && knots[i-1].y == knots[i].y) knots[i].x++;
					else if((knots[i-1].y + 2) == knots[i].y && knots[i-1].x == knots[i].x) knots[i].y--;
					else if((knots[i-1].y - 2) == knots[i].y && knots[i-1].x == knots[i].x) knots[i].y++;
					else
					{
						if(knots[i].x < knots[i-1].x && knots[i].y < knots[i-1].y) { knots[i].x++; knots[i].y++; }
						else if(knots[i].x > knots[i-1].x && knots[i].y > knots[i-1].y) { knots[i].x--; knots[i].y--; }
						else if(knots[i].x > knots[i-1].x && knots[i].y < knots[i-1].y) { knots[i].x--; knots[i].y++; }
						else if(knots[i].x < knots[i-1].x && knots[i].y > knots[i-1].y) { knots[i].x++; knots[i].y--; }
					}
					visited.insert(knots[9].getHash());
				}
			}
		}
	}
	cout << "PART 2 visited = " << visited.size() << endl;
}

int main()
{
	part1();
	part2();
	return 0;
}
