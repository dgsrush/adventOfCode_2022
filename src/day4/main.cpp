#include"ReadFile.h"
#include<iostream>
#include<vector>

void readInput(std::vector<std::string> *v)
{
	//mhr::ReadFile inf("sample_input.txt");
	mhr::ReadFile inf("input.txt");
	std::string ll;
	while(inf.readLine(ll))
	{
		if(ll.length() > 0)
			v->push_back(ll);
	}
	inf.close();
}

std::string to_string(char c)
{
	char buf[2];
	buf[0] = c;
	buf[1] = 0;
	std::string ss(buf);
	return ss;
}

void tokenize(std::string &str, std::string &delims, std::vector<int> &ll)
{
	std::string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		std::string chr = to_string(str[i]);
		if(delims.find(chr) != std::string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(std::stoi(tok));
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(std::stoi(tok));
}

int main()
{
	std::vector<std::string> ll;
	readInput(&ll);
	std::string delims = "-,";
	int total1 = 0;
	int total2 = 0;
	for(std::string ss : ll)
	{
		std::vector<int> vv;
		tokenize(ss, delims, vv);

		if(vv[0] <= vv[2] && vv[1] >= vv[3]) total1++;
		else if(vv[2] <= vv[0] && vv[3] >= vv[1]) total1++;

		if(vv[0] >= vv[2] && vv[0] <= vv[3]) total2++;
		else if(vv[1] >= vv[2] && vv[1] <= vv[3]) total2++;
		else if(vv[2] >= vv[0] && vv[2] <= vv[1]) total2++;
		else if(vv[3] >= vv[0] && vv[3] <= vv[1]) total2++;
	}
	std::cout << "PART 1 total = " << total1 << std::endl;
	std::cout << "PART 2 total = " << total2 << std::endl;
	return 0;
}
