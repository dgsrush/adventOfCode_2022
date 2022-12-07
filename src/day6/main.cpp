#include<iostream>
#include<unordered_set>
#include"AocUtils.h"

using std::cout;
using std::endl;

void calc(int size, int part)
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	for(std::string ss : ll)
	{
		int cnt = ss.length();
		for(int i = 0; i < cnt-size; i++)
		{
			std::unordered_set<char> packet;
			for(int j = 0; j < size; j++)
				packet.insert(ss[i + j]);
			if(packet.size() == size)
			{
				cout << "PART " << part << " index = " << i+size << endl;
				break;
			}
		}
	}
}

int main()
{
	calc(4, 1);
	calc(14, 2);
	return 0;
}
