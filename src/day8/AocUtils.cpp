#include"AocUtils.h"
#include"ReadFile.h"

void AocUtils::readInput(const std::string fileName, std::vector<std::string> *v)
{
	mhr::ReadFile inf(fileName);
	std::string ll;
	while(inf.readLine(ll))
	{
		if(ll.length() > 0)
			v->push_back(ll);
	}
	inf.close();
}

void AocUtils::tokenize(std::string &str, std::string &delims, std::vector<int> &ll)
{
	std::string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		std::string chr = str.substr(i, 1);
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

void AocUtils::tokenize(std::string &str, std::string &delims, std::vector<std::string> &ll)
{
	std::string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		std::string chr = str.substr(i, 1);
		if(delims.find(chr) != std::string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(tok);
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(tok);
}
