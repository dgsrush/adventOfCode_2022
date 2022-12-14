#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include"AocUtils.h"
#include"StrUtils.h"

using std::cout;
using std::endl;

#define LTHAN 1
#define GTHAN 2
#define EQL 3

class MBase
{
public:
	MBase() {}
	virtual ~MBase() = default;
	virtual bool isInt() { return false; }
	virtual bool isList() { return false; }
	virtual void print() {}
};

//******************************************************************

class MInt : public MBase
{
public:
	MInt(int i) : value(i) {}
	bool isInt() override { return true; }
	bool isList() override { return false; }
	void print() override;

	int value;
};

void MInt::print()
{
	cout << value << ",";
}

//******************************************************************

class MList : public MBase
{
public:
	~MList();
	bool isInt() override { return false; }
	bool isList() override { return true; }
	void print() override;
	int size() { return values.size(); }
	MBase * get(int i) { return values[i]; }
	void add(MBase *i) { values.push_back(i); }
	MBase * getNext();
	void reset() { cur = 0; }

	std::vector<MBase *> values;
	int cur = 0;
};

MList::~MList()
{
	for(MBase *val : values)
		delete val;
	values.clear();
}

MBase * MList::getNext()
{
	if(cur >= values.size()) return NULL;
	MBase *r = values[cur];
	cur++;
	return r;
}

void MList::print()
{
	cout << "[";
	for(MBase *value : values)
		value->print();
	cout << "]";
}

//******************************************************************

class Packet
{
public:
	Packet(std::string ss1, std::string ss2) : s1(ss1), s2(ss2) {}
	void print();
	bool rightOrder();
private:
	int compare(MBase *, MBase *);
	void parse(std::string &, MList &ml);
	std::string s1, s2;
};

void Packet::print()
{
	cout << "***********" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
}

void Packet::parse(std::string &ss, MList &ml)
{
	static std::string delims = "[,]";
	std::vector<std::string> ll;
	AocUtils::tokenizeWithDelims(ss, delims, ll);
	ll.erase(ll.begin());
	ll.pop_back();

	MList *cur = &ml;
	std::stack<MList *> stk;
	for(std::string s : ll)
	{
		if(s == ",") continue;

		if(AocUtils::isInteger(s))
		{
			MInt *ii = new MInt(std::stoi(s));
			cur->add(ii);
		}
		else if(s == "[")
		{
			MList *ll = new MList();
			cur->add(ll);
			stk.push(cur);
			cur = ll;
		}
		else if(s == "]")
		{
			cur = stk.top();
			stk.pop();
		}
	}
}

int Packet::compare(MBase *lt, MBase *rt)
{
	if(lt->isInt() && rt->isInt())
	{
		MInt *lhs = (MInt *)lt;
		MInt *rhs = (MInt *)rt;
		if(lhs->value < rhs->value) return LTHAN;
		else if(lhs->value == rhs->value) return EQL;
		return GTHAN;
	}
	else if(lt->isInt() && rt->isList())
	{
		MList *llt = new MList();
		llt->add(lt);
		return compare(llt, rt);
	}
	else if(lt->isList() && rt->isInt())
	{
		MList *rrt = new MList();
		rrt->add(rt);
		return compare(lt, rrt);
	}
	else if(lt->isList() && rt->isList())
	{
		MList *llt = (MList *)lt;
		MList *rrt = (MList *)rt;
		int cnt = 0;
		while(cnt < llt->size() && cnt < rrt->size())
		{
			int x = compare(llt->getNext(), rrt->getNext());
			if(x == LTHAN) return LTHAN;
			if(x == GTHAN) return GTHAN;
			cnt++;
		}
		if(cnt == llt->size() and cnt < rrt->size()) return LTHAN;
		if(cnt < llt->size() and cnt == rrt->size()) return GTHAN;
		return EQL;
	}
	return GTHAN;
}

bool Packet::rightOrder()
{
	MList r, l;
	parse(s1, l);
	parse(s2, r);
	int ii = compare(&l, &r);
	if(ii == LTHAN) return true;
	return false;
}

struct {
	bool operator()(std::string a, std::string b) const
	{
		std::vector<Packet> packets;
		packets.emplace_back(a, b);
		return packets[0].rightOrder();
	}
} customLess;

//******************************************************************

void calc()
{
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	std::vector<Packet> packets;
	int cnt = ll.size();
	for(int i = 0; i < cnt; i += 2)
		packets.emplace_back(ll[i], ll[i + 1]);

	int indx = 1;
	int total = 0;
	for(Packet p : packets)
	{
		if(p.rightOrder())
			total += indx;
		indx++;
	}
	cout << "PART 1 total = " << total << endl;

	std::string two = "[[2]]";
	std::string six = "[[6]]";
	int i1, i2;
	ll.push_back(two);
	ll.push_back(six);
	std::sort(ll.begin(), ll.end(), customLess);
	int i = 1;
	for(std::string ss : ll)
	{
		if(ss == two) i1 = i;
		else if(ss == six) i2 = i;
		i++;
	}
	cout << "PART 2 key = " << (i1 * i2) << endl;
}

int main()
{
	calc();
	return 0;
}
