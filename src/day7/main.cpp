#include<iostream>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::endl;

class dir
{
  public:
	dir(std::string name, dir *parent);
	~dir();
	std::string getName() { return name; }
	dir * getParent() { return parent; }
	long getSize() { return size; }
	void addDir(dir *add) { dirs.push_back(add); }
	void addSize(long siz) { size += siz; }
	void print(std::string tabs);
	long getTotal();
	void findDir(long need, long *min);

  private:
  	std::string name;
  	dir *parent;
  	std::vector<dir *> dirs;
  	long size;
};

dir::dir(std::string nam, dir *par)
{
	name = nam;
	parent = par;
	size = 0;
}

dir::~dir()
{
	for(dir *d : dirs)
		delete d;
}

void dir::print(std::string tabs)
{
	cout << tabs << name << " " << size << endl;
	tabs += "\t";
	for(dir *d : dirs)
		d->print(tabs);
}

long dir::getTotal()
{
	long total = 0;
	if(size <= 100000) total = size;
	for(dir *d : dirs)
		total += d->getTotal();
	return total;
}

void dir::findDir(long need, long *min)
{
	if(size >= need && size < *min)
		*min = size;
	for(dir *d : dirs)
		d->findDir(need, min);
}

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	dir *topDir = new dir("/", NULL);
	dir *curDir = topDir;

	std::string CD = "$ cd";
	std::string SPACE = " ";
	std::string DOLLAR = "$";
	std::string DIR = "dir";

	for(std::string ss : ll)
	{
		if(mhr::StrUtils::startsWith(ss, CD))
		{
			std::string dirName = ss.substr(5);

			if(dirName == "/") {}
			else if(dirName == "..")
			{
				curDir->getParent()->addSize(curDir->getSize());
				curDir = curDir->getParent();
			}
			else
			{
				dir *newDir = new dir(dirName, curDir);
				curDir->addDir(newDir);
				curDir = newDir;
			}
		}
		else if(!mhr::StrUtils::startsWith(ss, DOLLAR))
		{
			std::vector<std::string> tkns;
			AocUtils::tokenize(ss, SPACE, tkns);
			if(tkns.size() == 2 && tkns[0] != DIR)
				curDir->addSize(std::stoi(tkns[0]));
		}
	}
	while(curDir != topDir)
	{
		curDir->getParent()->addSize(curDir->getSize());
		curDir = curDir->getParent();
	}

	long total = topDir->getTotal();
	cout << "PART 1 total = " << total << endl;

	long req = 30000000 - (70000000 - topDir->getSize());
	long min = LONG_MAX;
	topDir->findDir(req, &min);
	cout << "PART 2 total = " << min << endl;
	delete topDir;
}

int main()
{
	calc();
	return 0;
}
