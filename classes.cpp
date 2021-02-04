#include<bits/stdc++.h>
using namespace std;

enum eDir
{
    STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6
};

class cball
{
    private:
        int x,y;
        int originalx,originaly;
        eDir direction;
    public:
        cball(int posx,int posy)
        {
            originalx = posx;
            originaly = posy;
            x = posx;
            y = posy;
            direction = STOP;
        }
        void reset()
        {
            x = originalx;
            y = originaly;
            direction = STOP;
        }
        void changedirection(eDir d)
        {
            direction = d;
        }
        void randomdirection()
        {
        	direction = (eDir)(rand()%6 +1);
		}
		inline int getx(){return x;}
		inline int gety(){return y;}
		inline eDir getdirection(){return direction;}
		
		void move()
		{
			switch(direction)
			{
				case STOP:
					break;
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UPLEFT:
					x--;y--;
					break;
				case DOWNLEFT:
					x--;y++;
					break;
				case UPRIGHT:
					x++;y--;
					break;
				case DOWNRIGHT:
					x++;y++;
					break;
				default:
					break;
			}
		}
		friend ostream & operator<<(ostream & o, cball c)
		{
			o << "Ball [" <<c.x <<","<< c.y <<"][" <<c.direction <<"]";
			return o;
		}
};
class cpaddle
{
	private:
		int x,y;
		int originalx, originaly;
	public:
		cpaddle()
		{
			x = y = 0;
		}
		cpaddle(int posx,int posy) : cpaddle()
		{
			originalx = posx;
			originaly = posy;
			x= posx;
			y = posy;
			
		}
	inline void reset(){ x = originalx; y=originaly;}
	inline int getx(){ return x;}
	inline int gety(){return y;}
	inline void moveup() {y--;}
	inline void movedown(){ y++;}
	friend ostream & operator<<(ostream & o, cpaddle c)
	{
		o<<"Paddle [" <<c.x<<","<<c.y<<"]";
		return 0;	
	}	
		
};
int main()
{
	cball c(0,0);
	cout<< c <<endl;
	c.randomdirection();
	cout<< c<<endl;
	c.move();
	cout<<c<<endl;
	c.randomdirection();
	c.move();
	cout<<c<<endl;
	c.randomdirection();
	c.move();
	cout<<c<<endl;

    return 0;
}
