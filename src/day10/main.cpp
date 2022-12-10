#include<iostream>
#include<string>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::endl;

class Comm
{
  public:
    Comm() : x(1), cycle(0), strength(0), raster(0) {}
	void noop();
	void addx(long);
	void report();

  private:
	void eval();
  	long x, cycle, strength, raster;
};

void Comm::eval()
{
	if(raster == x-1 || raster == x || raster == x+1)
		cout << "#";
	else
		cout << ".";
	raster++;
	if(raster == 40)
	{
		cout << endl;
		raster = 0;
	}

	if(cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
		strength += (x * cycle);
}

void Comm::noop()
{
	cycle++;
	eval();
}

void Comm::addx(long add)
{
	noop();
	noop();
	x += add;
}

void Comm::report()
{
	cout << endl << "PART 1 strength = " << strength << endl;
}

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	cout << "PART 2 = " << endl;
	Comm comm;
	for(std::string ss : ll)
	{
		if(ss == "noop")
			comm.noop();
		else
			comm.addx(std::stoi(ss.substr(5)));
	}
	comm.report();
}

int main()
{
	calc();
	return 0;
}
