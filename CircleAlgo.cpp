#include<iostream>
#include<cmath>
using namespace std;
void MidPoint(int x, int y, int r)
{
	int x1 = 0;
	int y1 = r;
	cout<<"X: "<<x<<" Y: "<<y<<"\nRadius: "<<r<<endl;
	cout<<"let the initial point be=> ("<<x1<<" , "<<y1<<" )"<<endl;
	int p = 1 - r;
	cout<<"Initial p = 1 - r = "<<p<<endl;
	int steps = 1;
	cout<<"if p<0 then\n  => x = x +1\n  => p = p + 2x + 3\nelse:\n  => x = x + 1\n  => y = y + 1\n  => p = p + 2(x-y) + 5"<<endl;
	cout<<endl;
	cout<<"x: "<<(x1 + x)<<" | y: "<<(y1 + y)<<" || p: "<<p<<endl;
	while(x1 < y1)
	{
		if(p < 0)
		{
			x1++;
			p = p + (2 * x1) + 3;
		}
		else
		{
			x1++;
			y1--;
			if(x1>y1)
				break;
			p = p + (2 * (x1 - y1)) + 5;
		}
		cout<<"x: "<<(x1 + x)<<" | y: "<<(y1 + y)<<" || p: "<<p<<endl;
		steps++;
	}
	cout<<"Number of Steps: "<<steps<<endl;
}
void Bresh(int x, int y, int r)
{
	/*
	1) Find initial d=> d = 3-2r
	2) initialise y = r
	3) if(d<0)=>d= d + 4x + 6; x++;
	   else=> d = d + 4(x-y) + 10; x++; y--;
	4) do step (2) and (3) while (x!=y)
	*/
	int d = 3 - (2 * r);
	int y1 = r;
	int x1 = 0;
	cout<<"X: "<<x<<" Y: "<<y<<"\nRadius: "<<r<<endl;
	cout<<"let the initial point be=> ("<<x1<<" , "<<y1<<" )"<<endl;
	cout<<"Initial d = 3 - 2r = "<<d<<endl;
	cout<<"if d<0 then\n  => x = x +1\n  => d = d + 4x + 6\nelse:\n  => x = x + 1\n  => y = y + 1\n  => d = d + 4(x1 - y1) + 10"<<endl;
	cout<<"x: "<<(x1 + x)<<" | y: "<<(y1 + y)<<" || d: "<<d<<endl;
	while(x1 < y1)
	{
		if(d<0)
		{
			x1++;
			d = d + (4 * x1) + 6;
		}
		else
		{
			x1++;
			y1--;
			if(x1>y1)
				break;
			d = d + (4 * (x1 - y1) )+ 10;
		}
		cout<<"x: "<<(x1 + x)<<" | y: "<<(y1 + y)<<" || d: "<<d<<endl;
	}
}

int main()
{
	int x1, y1, r, input;
	cout<<"Circle Algos for Computer Graphics"<<endl;
	do
	{
		cout<<"\n\nEnter which algo you want to use:\n1)Mid-Point\n2)Breshenan\n3)Exit\n: ";
		cin>>input;
		if(input>=3)
			break;
		cout<<"\nInput all the four points with spacing in the format of x y r(eg: '2 5 10')"<<endl;
		cout<<": ";
		cin>>x1>>y1>>r;
		switch(input)
		{
			case 1:
				MidPoint(x1, y1, r);
				break;
			case 2:
				Bresh(x1, y1, r);
				break;
		}
	}
	while(input<3);
	return 0;
}
