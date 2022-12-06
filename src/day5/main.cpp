#include<iostream>
#include<array>
#include<stack>
#include"StrUtils.h"
#include"AocUtils.h"

using std::cout;
using std::endl;

void reverseStacks(std::array<std::stack<char>, 9> &stacks)
{
	for(int i = 0; i < 9; i++)
	{
		std::vector<char> tmp;
		while(!stacks[i].empty())
		{
			tmp.push_back(stacks[i].top());
			stacks[i].pop();
		}
		for(int j = 0; j < tmp.size(); j++)
			stacks[i].push(tmp[j]);
	}
}

void printTops(std::array<std::stack<char>, 9> &stacks)
{
	for(int i = 0; i < 9; i++)
	{
		if(!stacks[i].empty())
			cout << stacks[i].top();
	}
	cout << endl;
}

void part1()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::string BRACKET = "[";
	std::string MOVE = "move";
	std::string SPACE = " ";
	bool isFirstMove = true;
	std::array<std::stack<char>, 9> stacks;

	for(std::string ss : ll)
	{
		if(mhr::StrUtils::indexOf(ss, BRACKET) >= 0)
		{
			int ii = 1;
			for(int i = 0; i < 9; i++)
			{
				if(ii > ss.length()) break;
				if(ss[ii] != ' ')
					stacks[i].push(ss[ii]);
				ii += 4;
			}
		}
		else if(mhr::StrUtils::indexOf(ss, MOVE) == 0)
		{
			if(isFirstMove)
			{
				reverseStacks(stacks);
				isFirstMove = false;
			}
			std::vector<std::string> moves;
			AocUtils::tokenize(ss, SPACE, moves);
			int mcnt = std::stoi(moves[1]);
			int from = std::stoi(moves[3]) - 1;
			int to = std::stoi(moves[5]) - 1;
			for(int i = 0; i < mcnt; i++)
			{
				stacks[to].push(stacks[from].top());
				stacks[from].pop();
			}
		}
	}

	cout << "PART 1 = ";
	printTops(stacks);
}

void part2()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::string BRACKET = "[";
	std::string MOVE = "move";
	std::string SPACE = " ";
	bool isFirstMove = true;
	std::array<std::stack<char>, 9> stacks;

	for(std::string ss : ll)
	{
		if(mhr::StrUtils::indexOf(ss, BRACKET) >= 0)
		{
			int ii = 1;
			for(int i = 0; i < 9; i++)
			{
				if(ii > ss.length()) break;
				if(ss[ii] != ' ')
					stacks[i].push(ss[ii]);
				ii += 4;
			}
		}
		else if(mhr::StrUtils::indexOf(ss, MOVE) == 0)
		{
			if(isFirstMove)
			{
				reverseStacks(stacks);
				isFirstMove = false;
			}
			std::vector<std::string> moves;
			AocUtils::tokenize(ss, SPACE, moves);
			int mcnt = std::stoi(moves[1]);
			int from = std::stoi(moves[3]) - 1;
			int to = std::stoi(moves[5]) - 1;

			std::vector<char> tmp;
			for(int i = 0; i < mcnt; i++)
			{
				tmp.push_back(stacks[from].top());
				stacks[from].pop();
			}
			for(int i = tmp.size() - 1; i >=0 ; i--)
				stacks[to].push(tmp[i]);
		}
	}

	cout << "PART 2 = ";
	printTops(stacks);
}

int main()
{
	part1();
	part2();
	return 0;
}
