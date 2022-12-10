import 'dart:io';

class Pos
{
	int x = 100;
	int y = 100;
	Pos();
	String getHash() { return x.toString() + ":" + y.toString(); }
	bool isClose(Pos p)
	{
		if(p.x == (x-1) && p.y == y) return true;
		if(p.x == (x+1) && p.y == y) return true;
		if(p.y == (y-1) && p.x == x) return true;
		if(p.y == (y+1) && p.x == x) return true;
		if(p.y == (y-1) && p.x == (x-1)) return true;
		if(p.y == (y-1) && p.x == (x+1)) return true;
		if(p.y == (y+1) && p.x == (x-1)) return true;
		if(p.y == (y+1) && p.x == (x+1)) return true;
		return false;
	}
}

void main()
{
	part1();
	part2();
}

void part1()
{
	Pos head = Pos();
	Pos tail = Pos();
	Set<String> visited = Set();
	visited.add(tail.getHash());

	//File file = File('sample_input1.txt');
	File file = File('input.txt');
	List<String> ll = file.readAsLinesSync();
	for(final ss in ll)
	{
		final tkns = ss.split(' ');
		String dir = tkns[0];
		int cnt = int.parse(tkns[1]);

		for(var i = 0; i < cnt; i++)
		{
			if(dir == "U") head.y--;
			else if(dir == "D") head.y++;
			else if(dir == "L") head.x--;
			else if(dir == "R") head.x++;

			if(!tail.isClose(head))
			{
				if((head.x + 2) == tail.x && head.y == tail.y) tail.x--;
				else if((head.x - 2) == tail.x && head.y == tail.y) tail.x++;
				else if((head.y + 2) == tail.y && head.x == tail.x) tail.y--;
				else if((head.y - 2) == tail.y && head.x == tail.x) tail.y++;
				else
				{
					if(tail.x < head.x && tail.y < head.y) { tail.x++; tail.y++; }
					else if(tail.x > head.x && tail.y > head.y) { tail.x--; tail.y--; }
					else if(tail.x > head.x && tail.y < head.y) { tail.x--; tail.y++; }
					else if(tail.x < head.x && tail.y > head.y) { tail.x++; tail.y--; }
				}
				visited.add(tail.getHash());
			}
		}
	}
	print("PART 1 visited = " + visited.length.toString());
}

void part2()
{
	List<Pos> knots = [
	    new Pos(), new Pos(), new Pos(), new Pos(), new Pos(),
	    new Pos(), new Pos(), new Pos(), new Pos(), new Pos()]; //this is dumb
	Set<String> visited = Set();
	visited.add(knots[9].getHash());

	//File file = File('sample_input2.txt');
	File file = File('input.txt');
	List<String> ll = file.readAsLinesSync();
	for(final ss in ll)
	{
		final tkns = ss.split(' ');
		String dir = tkns[0];
		int cnt = int.parse(tkns[1]);

		for(int j = 0; j < cnt; j++)
		{
			if(dir == "U") knots[0].y--;
			else if(dir == "D") knots[0].y++;
			else if(dir == "L") knots[0].x--;
			else if(dir == "R") knots[0].x++;

			for(int i = 1; i < 10; i++)
			{
				if(!knots[i].isClose(knots[i-1]))
				{
					if((knots[i-1].x + 2) == knots[i].x && knots[i-1].y == knots[i].y) knots[i].x--;
					else if((knots[i-1].x - 2) == knots[i].x && knots[i-1].y == knots[i].y) knots[i].x++;
					else if((knots[i-1].y + 2) == knots[i].y && knots[i-1].x == knots[i].x) knots[i].y--;
					else if((knots[i-1].y - 2) == knots[i].y && knots[i-1].x == knots[i].x) knots[i].y++;
					else
					{
						if(knots[i].x < knots[i-1].x && knots[i].y < knots[i-1].y) { knots[i].x++; knots[i].y++; }
						else if(knots[i].x > knots[i-1].x && knots[i].y > knots[i-1].y) { knots[i].x--; knots[i].y--; }
						else if(knots[i].x > knots[i-1].x && knots[i].y < knots[i-1].y) { knots[i].x--; knots[i].y++; }
						else if(knots[i].x < knots[i-1].x && knots[i].y > knots[i-1].y) { knots[i].x++; knots[i].y--; }
					}
					visited.add(knots[9].getHash());
				}
			}
		}
	}
	print("PART 2 visited = " + visited.length.toString());
}
