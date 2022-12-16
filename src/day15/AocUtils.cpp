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

void AocUtils::tokenize(std::string &str, std::string &delims, std::vector<long> &ll)
{
	std::string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		std::string chr = str.substr(i, 1);
		if(delims.find(chr) != std::string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(std::stol(tok));
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(std::stoi(tok));
}

void AocUtils::tokenize(std::string &str, std::string &delims, std::vector<unsigned long long> &ll)
{
	std::string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		std::string chr = str.substr(i, 1);
		if(delims.find(chr) != std::string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(std::stoll(tok));
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(std::stoi(tok));
}

void AocUtils::tokenize(std::string &str, std::string &delims, std::vector<long long> &ll)
{
	std::string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		std::string chr = str.substr(i, 1);
		if(delims.find(chr) != std::string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(std::stoll(tok));
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

void AocUtils::tokenizeWithDelims(std::string &str, std::string &delims, std::vector<std::string> &ll)
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
			ll.push_back(chr);
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(tok);
}

bool AocUtils::isInteger(std::string &str)
{
	try
	{
		std::stoi(str);
		return true;
	}
	catch(...) {}
	return false;
}

bool AocUtils::isLong(std::string &str)
{
	try
	{
		std::stol(str);
		return true;
	}
	catch(...) {}
	return false;
}

bool AocUtils::isLongLong(std::string &str)
{
	try
	{
		std::stoll(str);
		return true;
	}
	catch(...) {}
	return false;
}
