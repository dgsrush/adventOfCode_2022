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

int valueOf(int c)
{
	if(c > 96) return c - 96;
	return c - 38;
}

void part1()
{
	std::vector<std::string> ll;
	readInput(&ll);
	int score = 0;
	for(std::string ss : ll)
	{
		std::string s1 = ss.substr(0, ss.length() / 2);
		std::string s2 = ss.substr(ss.length() / 2);
		for(char c : s1)
		{
			if(s2.find(c) != std::string::npos)
			{
				score += valueOf(c);
				break;
			}
		}
	}
	std::cout << "PART 1 score = " << score << std::endl;
}

void part2()
{
	std::vector<std::string> ll;
	readInput(&ll);
	int score = 0;
	int cnt = ll.size();
	for(int i = 0; i < cnt; i += 3)
	{
		std::string s1 = ll[i];
		std::string s2 = ll[i + 1];
		std::string s3 = ll[i + 2];
		for(char c : s1)
		{
			if(s2.find(c) != std::string::npos && s3.find(c) != std::string::npos)
			{
				score += valueOf(c);
				break;
			}
		}
	}
	std::cout << "PART 2 score = " << score << std::endl;
}

int main()
{
	part1();
	part2();
	return 0;
}
