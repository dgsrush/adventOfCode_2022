#include<iostream>
#include<string>
#include<algorithm>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::cerr;
using std::endl;

class Monkey
{
public:
	Monkey() : op(' '), opValue(""), testValue(0), trueTo(0), falseTo(0), inspected(0) {}
	void addItem(long long i) { items.push_back(i); }
	void setOp(char opr, const std::string &val) { op = opr; opValue = val; }
	void setTestValue(long long val) { testValue = val; }
	void setTrueThrowTo(int val) { trueTo = val; }
	void setFalseThrowTo(int val) { falseTo = val; }
	void print();
	void processItems(std::vector<Monkey *> &monkeys, long long mm, int part);
	int getInspected() { return inspected; }
	long long getTestValue() { return testValue; }
private:
	std::vector<long long> items;
	char op;
	std::string opValue;
	long long testValue;
	int trueTo, falseTo;
	long long inspected;
};

void Monkey::processItems(std::vector<Monkey *> &monkeys, long long mm, int part)
{
	while(items.size() > 0)
	{
		inspected++;

		long long item = items[0];
		long long opVal = item;
		if(opValue != "old")
			opVal = std::stoll(opValue);
		if(op == '*')
			item *= opVal;
		else
			item += opVal;
		items.erase(items.begin());

		if(part == 1) item /= 3;
		else if(part == 2) item %= mm;

		if((item % testValue) == 0)
			monkeys[trueTo]->addItem(item);
		else
			monkeys[falseTo]->addItem(item);
	}
}

void Monkey::print()
{
	cout << "--------------------------" << endl;
	cout << "ITEMS:" << endl;;
	for(long long item : items)
		cout << "         " << item << endl;
	cout << "OP:      " << op << " " << opValue << endl;
	cout << "TEST:    " << testValue << endl;
	cout << "TRUETO:  " << trueTo << endl;
	cout << "FALSETO: " << falseTo << endl;
}

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);
	std::string MONKEY = "Monkey";
	std::string DELIMS = ", ";

	for(int part = 1; part < 3; part++)
	{
		std::vector<Monkey *> monkeys;
		long long mm = 1;

		int cnt = ll.size();
		for(int i = 0; i < cnt; i++)
		{
			std::string ss = ll[i];
			if(mhr::StrUtils::startsWith(ss, MONKEY))
			{
				Monkey *m = new Monkey();

				std::string itms = ll[i+1].substr(18);
				std::vector<long long> items;
				AocUtils::tokenize(itms, DELIMS, items);
				for(long long item : items)
					m->addItem(item);

				std::string opr = ll[i+2].substr(23,1);
				std::string value = ll[i+2].substr(25);
				m->setOp(opr[0], value);

				std::string testVal = ll[i+3].substr(21);
				m->setTestValue(std::stol(testVal));
				mm *= std::stol(testVal);

				std::string trueTo = ll[i+4].substr(29);
				m->setTrueThrowTo(std::stol(trueTo));

				std::string falseTo = ll[i+5].substr(30);
				m->setFalseThrowTo(std::stol(falseTo));

				monkeys.push_back(m);
			}
		}

		int cc = 20;
		if(part == 2) cc = 10000;
		for(int i = 0; i < cc; i++)
		{
			for(Monkey *m : monkeys)
				m->processItems(monkeys, mm, part);
		}

		std::vector<long long> totals;
		for(Monkey *m : monkeys)
		{
			totals.push_back(m->getInspected());
			cout << "Inspected: " << m->getInspected() << endl;
		}
		std::sort(totals.begin(), totals.end());
		long long total = totals[totals.size()-1] * totals[totals.size()-2];
		cout << "PART " << part << " monkey business = " << total << endl;

		for(Monkey *m : monkeys)
			delete m;
		monkeys.clear();
	}
}

int main()
{
	calc();
	return 0;
}
