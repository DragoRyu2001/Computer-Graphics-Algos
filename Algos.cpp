#include<iostream>
#include<cmath>
using namespace std;
void DDALine(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps;
	float xinc, yinc, x, y;
	x = x1;
	y = y1;
	cout<<"\nSOLUTION\nX1: "<<x1<<" Y1: "<<y1<<"\nX2: "<<x2<<" Y2: "<<y2<<endl;
	cout<<"Points given: ("<<x1<<", "<<y1<<")-> ("<<x2<<", "<<y2<<");"<<endl;
	cout<<"dx = x2 - x1= "<<dx<<endl;
	cout<<"dy = y2 - y1= "<<dy<<endl;
	if(abs(dx)>abs(dy))
	{
		steps = abs(dx);
		cout<<"Since dx is greater than dy => Number of steps = "<<steps<<endl;
	}
	else if(abs(dx)<abs(dy))
	{
		steps = abs(dy);
		cout<<"Since dy is greater than dx => Number of steps = "<<steps<<endl;
	}
	else if(abs(dx) == abs(dy))
	{
		steps = abs(dx);
		cout<<"Since dx is equal to dy => Number of steps = dx = dy = "<<steps<<endl;
	}
	cout<<"dx: "<<dx<<" | dy: "<<dy<<endl;
	cout<<"Number of Intermediate points: "<<(steps-1)<<endl;
	xinc = (float)dx/steps;
	yinc = (float)dy/steps;
	cout<<"Xinc is: dx/steps = "<<xinc<<endl;
	cout<<"yinc is: dy/steps = "<<yinc<<endl;
	cout<<"X: "<<round(x)<<"| y: "<<round(y)<<endl;
	for(int i = 0; i< steps; i++)
		{
			x = x + xinc;
			y = y+ yinc;
			cout<<"X: "<<x<<" => "<<round(x)<<"| y: "<<y<<" => "<<round(y)<<endl;
		}

}
void MidPointLine(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	float d;
	bool s = false;
	int inter = 0;
	cout<<"\nSOLUTION\nX1: "<<x1<<" Y1: "<<y1<<"\nX2: "<<x2<<" Y2: "<<y2<<endl;
	cout<<"\ndx = x2 - x1 = "<<dx<<"\ndy = y2 - y1 = "<<dy<<endl;
	if(dy>dx)
	{
		cout<<"Since dy is greater than dx...."<<endl;
		int temp = x1;
		x1 = y1;
		y1 = temp;
		temp = x2;
		x2 = y2;
		y2 = temp;
		cout<<"Switching x and y values\n";
		dx = x2-x1;
		dy = y2-y1;
		cout<<"Therefore new dx and dy are as follows\ndx = "<<dx<<"\ndy = "<<dy<<endl;
		s = true;
	}
	d = dy - (dx/2);
	cout<<"d = dy - (dx/2) = "<<d<<"\n if d<0 \n  => d = d + dy\n  =>x++\n else\n  =>d = d + (dy-dx)\n  =>x++ and y++"<<endl;
	cout<<"\n\nX: "<<x1<<"| y: "<<y1<<" | d: "<<d<<endl;
	while(x1<x2 || y1<y2)
	{
		if(d<0)
		{
			d = d + dy;
			x1++;
		}
		else
		{
			d = d + (dy-dx);
			x1++;
			y1++;
		}
		cout<<"X: "<<x1<<"| y: "<<y1<<" | d: "<<d<<endl;
		inter++;
	}
	if(s)
	{
		cout<<"NOTE: Switch the values of x and y and redraw the table"<<endl;
	}
	cout<<"\nNumber of Intermediate points = "<<inter-1<<endl;
}
void GeneralLine(int x1, int y1, int x2, int y2)
{
	int dx = x2-x1;
	int dy = y2-y1;
	int inter = 0;
	bool s = false;
	cout<<"\nSOLUTION\nX1: "<<x1<<" Y1: "<<y1<<"\nX2: "<<x2<<" Y2: "<<y2<<endl;
	cout<<"\ndx = x2 - x1 = "<<dx<<"\ndy = y2 - y1 = "<<dy<<endl;
	if(abs(dy)>abs(dx))
	{
		cout<<"Since dy is greater than dx...."<<endl;
		int temp = x1;
		x1 = y1;
		y1 = temp;
		temp = x2;
		x2 = y2;
		y2 = temp;
		cout<<"Switching x and y values\n";
		dx = x2-x1;
		dy = y2-y1;
		cout<<"Therefore new dx, dy are as follows:\ndx: "<<dx<<"\ndy: "<<dy<<endl;
		s = true;
	}
	int xinc = 1;
	int yinc = 1;
	if(dx<0)
	{
		cout<<"Since dx is negative, x decreases by 1"<<endl;
		xinc = -1;
	}
	if(dy<0)
	{
		cout<<"Since dy is negative, y decreases by 1"<<endl;
		yinc = -1;
	}
	dx = abs(dx);
	dy = abs(dy);
	int a = 2*dy;
	cout<<"a = 2*dy = "<<a<<endl;
	int b = 2*(dy-dx);
	cout<<"b = 2*(dy-dx) = "<<b<<endl;
	int d = (2*dy) - dx;
	cout<<"Initial d = (2*dy) - dx = "<<d<<endl;
	cout<<"If d<0 then d = d + a and only x changes\nelse d = d + b and both x and y change"<<endl;
	cout<<"\n\nX: "<<x1<<"| y: "<<y1<<" | d: "<<d<<endl;
	while(x1 != x2 || y1 != y2)
	{
	
		if(d<0)
		{
			x1 = x1 + xinc;
			d = d + a;
		}
		else
		{
			y1 = y1 + yinc;
			x1 = x1 + xinc;
			d = d + b;
		}
		cout<<"X: "<<x1<<"| y: "<<y1<<" | d: "<<d<<endl;
		inter++;
	}
	if(s)
	{
		cout<<"NOTE: Switch the values of x and y and redraw the table"<<endl;
	}
	cout<<"Therefore number of intermediate points = "<<inter-1<<endl;
}
void MidPointCircle(int x, int y, int r)
{
	int x1 = 0;
	int y1 = r;
	cout<<"\nSOLUTION\nX: "<<x<<" Y: "<<y<<"\nRadius: "<<r<<endl;
	cout<<"let the initial point be=> ("<<x1<<" , "<<y1<<" )"<<endl;
	int p = 1 - r;
	cout<<"Initial p = 1 - r = "<<p<<endl;
	int steps = 1;
	cout<<"if p<0 then\n  => x = x + 1\n  => p = p + 2x + 3\nelse:\n  => x = x + 1\n  => y = y - 1\n  => p = p + 2(x-y) + 5"<<endl;
	cout<<endl;
	cout<<"x: "<<x1<<" => "<<(x1 + x)<<" | y: "<<y1<<" => "<<(y1 + y)<<" || p: "<<p<<endl;
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
		cout<<"x: "<<x1<<" => "<<(x1 + x)<<" | y: "<<y1<<" => "<<(y1 + y)<<" || p: "<<p<<endl;
		steps++;
	}
	cout<<"Number of Steps: "<<steps<<endl;
}
void BreshCircle(int x, int y, int r)
{
	int d = 3 - (2 * r);
	int y1 = r;
	int x1 = 0;
	cout<<"\nSOLUTION\nX: "<<x<<" Y: "<<y<<"\nRadius: "<<r<<endl;
	cout<<"let the initial point be=> ("<<x1<<" , "<<y1<<" )"<<endl;
	cout<<"Initial d = 3 - 2r = "<<d<<endl;
	cout<<"if d<0 then\n  => x = x + 1\n  => d = d + 4x + 6\nelse:\n  => x = x + 1\n  => y = y - 1\n  => d = d + 4(x1 - y1) + 10"<<endl;
	cout<<"x: "<<x1<<" => "<<(x1 + x)<<" | y: "<<y1<<" => "<<(y1 + y)<<" || d: "<<d<<endl;
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
		cout<<"x: "<<x1<<" => "<<(x1 + x)<<" | y: "<<y1<<" => "<<(y1 + y)<<" || d: "<<d<<endl;
	}
}
void MidPointEllipse(int x1, int y1, int a, int b)
{
	/*
	1)if(a>b)
		x++;
	2)else
		swap values;
	3)Initial point (0,b)
	3) initial p = (b^2) - (a^2)*b + (a^2)/4
	4) p next  = p old + 2(b^2)x + 1 + b^2 and x++ for p<0
	5) p next = p old + 2(b^2)x+b^2-2(a^2)y  and x++, y-- for p>=0
	6) Loop till (a,0)
	*/
	if(a<b)
	{
		/*Swap Values*/
		int temp;
		temp = a;
		a = b;
		b = temp;
		cout<<"Values have been switched"<<endl;
	}
	int x = 0, y = b;
	int a2 = pow(a, 2);
	int b2 = pow(b, 2);
	float p = b2 - (a2*b) + (a2/4);
	int dy = 2*a2*y;
	int dx = 2*b2*x;
	cout<<"Let a = Major Axis radius = "<<a<<"\nLet b = Minor Axis radius = "<<b<<endl;
	cout<<"Region 1\n"<<endl;
	cout<<"Initial p = (b^2) - (a^2)*b + (a^2)/4 = "<<p<<endl;
	cout<<"DY = 2(a^2)y = "<<dy<<" |DX = 2*(b^2)x = "<<dx<<endl;
	cout<<"while(dy>dx)\nif(p<0)\n	=>x++ \n	=>p = p + dx + 1 + b^2\n else\n	=>x++ \n	=>y-- \n	=>p = p + dx + (b^2) - dy\n"<<endl;
	cout<<"X: "<<x<<" => "<<x+x1<<" | Y: "<<y<<" => "<<y+y1<<" || P: "<<p<<endl;
	while(dy>dx)
	{
		if(dy<=dx)
		{
			break;
		}
		if(p<0)
		{
			x++;
			dx = 2*b2*x;
			p = p + (2*b2*x) + 1 + b2;
		}
		else
		{
			x++;
			y--;
			dx = 2*b2*x;
			dy = 2*a2*y;
			p = p + dx + b2 - dy;
			
		}
		
		cout<<"X: "<<x<<" => "<<x+x1<<" | Y: "<<y<<" => "<<y+y1<<" || P: "<<p<<" dy: "<<dy<<" dx: "<<dx<<endl;
		
	}
	cout<<"End of Region 1"<<endl;
	cout<<"Region 2\n"<<endl;
	p = (b2*pow((x+0.5), 2)) + (a2*pow((y-1), 2)) - (a2*b2);
	cout<<"Initial p = b^2*(x+ 1/2)^2 + a^2*(y - 1)^2 - (a^2 * b^2) = "<<p<<endl;
	cout<<" while(y>0)\nif(p>0)\n	=> y-- \n	=> dy = 2(a^2)y \n	=> p = p - dy + (a^2)\n else\n	=> y-- \n	=> x++ \n	=> dy = 2(a^2)y \n	=> dx = 2(b^2)x \n	=> p = p + dx - dy + (a^2)"<<endl;
	cout<<"Initial value of Region 2 = Last value of Region 1:\nX: "<<x<<" => "<<x+x1<<" | Y: "<<y<<" => "<<y+y1<<" || P: "<<p<<endl;
	while(y>0)
	{
		if(p>0)
		{
			y--;
			dy = 2*a2*y;
			p = p - dy + a2;
		}
		else
		{
			y--;
			x++;
			dy = 2*a2*y;
			dx = 2*b2*x;
			p = p + dx - dy + a2;
		}
		cout<<"X: "<<x<<" => "<<x+x1<<" | Y: "<<y<<" => "<<y+y1<<" || P: "<<p<<endl;
	}
	cout<<"End of Region 2"<<endl;
}

int main()
{
	int x1, y1, x2, y2, r, input, a, b;
	cout<<"Algos for Computer Graphics"<<endl;
	do
	{
		cout<<"\n\nEnter which algo you want to use:\nLINE ALGOS\n1)DDA(First Quadrant ->)\n2)Mid-Point(First Quadrant ->)\n3)General Formula(All Quadrants ->)\n\nCIRCLE ALGOS\n4)MidPoint Circle Algorithm\n5)Breshenham' Circle Algorithm\n\nELLIPSE\n6) MidPoint Ellipse\n7) Exit\n: ";
		cin>>input;
		if(input>=7)
		{
			break;
		}
		switch(input)
		{
			case 1:
				cout<<"\nInput all the four points with spacing in the format of x1 y1 x2 y2(eg: '2 5 8 2')"<<endl;
				cout<<": ";
				cin>>x1>>y1>>x2>>y2;
				DDALine(x1, y1, x2, y2);
				break;
			case 2:
				cout<<"\nInput all the four points with spacing in the format of x1 y1 x2 y2(eg: '2 5 8 2')"<<endl;
				cout<<": ";
				cin>>x1>>y1>>x2>>y2;
				MidPointLine(x1, y1, x2, y2);
				break;
			case 3:
				cout<<"\nInput all the four points with spacing in the format of x1 y1 x2 y2(eg: '2 5 8 2')"<<endl;
				cout<<": ";
				cin>>x1>>y1>>x2>>y2;
				GeneralLine(x1, y1, x2, y2);
				break;
			case 4:
				cout<<"\nInput all the three points with spacing in the format of x1 y1 r(eg: '5 2 10')"<<endl;
				cout<<": ";
				cin>>x1>>y1>>r;
				MidPointCircle(x1, y1, r);
				break;
			case 5:
				cout<<"\nInput all the three points with spacing in the format of x1 y1 r(eg: '5 2 10')"<<endl;
				cout<<": ";
				cin>>x1>>y1>>r;
				BreshCircle(x1, y1, r);
				break;
			case 6:
				cout<<"\nInput all the four points with spacing in the format of x1 y1 rx ry(eg: '5 2 10 5')"<<endl;
				cout<<": ";
				cin>>x1>>y1>>a>>b;
				MidPointEllipse(x1, y1, a, b);
				break;
		}
	}
	while(input<7);
	return 0;
}

