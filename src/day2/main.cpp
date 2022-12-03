#include"ReadFile.h"
#include<iostream>
#include<vector>

void readInput(std::vector<std::string> *v)
{
	mhr::ReadFile inf("input.txt");
	std::string ll;
	while(inf.readLine(ll))
	{
		if(ll.length() > 0)
			v->push_back(ll);
	}
	inf.close();
}

void part1()
{
	std::vector<std::string> ll;
	readInput(&ll);
	int score = 0;
	for(std::string ss : ll)
	{
		if(ss == "A X") score += (1 + 3);		//rock = rock
		else if(ss == "A Y") score += (2 + 6);	//rock < paper
		else if(ss == "A Z") score += (3 + 0);	//rock > scissors
		else if(ss == "B X") score += (1 + 0);	//paper > rock
		else if(ss == "B Y") score += (2 + 3);	//paper = paper
		else if(ss == "B Z") score += (3 + 6);	//paper < scissors
		else if(ss == "C X") score += (1 + 6);	//scissors < rock
		else if(ss == "C Y") score += (2 + 0);	//scissors > paper
		else if(ss == "C Z") score += (3 + 3);	//scissors = scissors
	}
	std::cout << "PART 1 score = " << score << std::endl;
}

void part2()
{
	std::vector<std::string> ll;
	readInput(&ll);
	int score = 0;
	for(std::string ss : ll)
	{
		if(ss == "A X") score += (3 + 0);		//rock lose
		else if(ss == "A Y") score += (1 + 3);	//rock draw
		else if(ss == "A Z") score += (2 + 6);	//rock win
		else if(ss == "B X") score += (1 + 0);	//paper lose
		else if(ss == "B Y") score += (2 + 3);	//paper draw
		else if(ss == "B Z") score += (3 + 6);	//paper win
		else if(ss == "C X") score += (2 + 0);	//scissors lose
		else if(ss == "C Y") score += (3 + 3);	//scissors draw
		else if(ss == "C Z") score += (1 + 6);	//scissors win
	}
	std::cout << "PART 2 score = " << score << std::endl;
}

int main()
{
	part1();
	part2();
	return 0;
}
