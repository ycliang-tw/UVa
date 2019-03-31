#include <iostream>
#include <string>
using namespace std;

enum {N = 0, E, S, W, F, R, L};
char dir[4] = {'N', 'E', 'S', 'W'};


class Robot
{
	public:
		int x, y, fid;
		bool lost;
	public:
		Robot(int x, int y, int fid)
			: x(x)
			, y(y)
			, fid(fid)
			, lost(false)
			{}
		void turn(char);
		int getx()	{ return x; }
		int gety() 	{ return y; }
		int getfid()	{ return fid; }
		void setflag()	{ lost = true; }
		bool getflag()	{ return lost; }
		void xminus()	{ x--; }
		void xplus()	{ x++; }
		void yminus()	{ y--; }
		void yplus()	{ y++; }
		void print();

};

int dton(char a){
	if(a == 'N')	return N;
	if(a == 'E')	return E;
	if(a == 'S')	return S;
	if(a == 'W')	return W;
	if(a == 'F')	return F;
	if(a == 'R')	return R;
	if(a == 'L')	return L;
	return -1;
}

int main(){
	int col, row;
	while(cin >> col >> row && (col && row)){
		int x, y;
		char cfid;
		bool table[55][55] = {};
		while(cin >> x >> y >> cfid){
			int fid = dton(cfid);
			string ins;
			Robot sim(x, y, fid);
			getline(cin, ins);
			getline(cin, ins);
			for(int i = 0; i < ins.length(); i++){
				if(ins[i] == 'F') {
					int tmp = sim.getfid();
					if(tmp == N)	sim.yplus();
					if(tmp == E)	sim.xplus();
					if(tmp == W)	sim.xminus();
					if(tmp == S)	sim.yminus();
				} else {
					sim.turn(ins[i]);	
				} 
				int tmp = sim.getfid();
				int posx = sim.getx(), posy = sim.gety();
				if( posx < 0 || posy < 0 || posx > col || posy > row ){			// logically should check if cross boundary after FORWARD!
					if(tmp == N)	sim.yminus();
					if(tmp == E)	sim.xminus();
					if(tmp == W)	sim.xplus();
					if(tmp == S)	sim.yplus();
					posx = sim.getx(), posy = sim.gety();						//  bugs alert !!!!   WA without this line !  cause pos changes!
					if( table[posx][posy] != true )	{ sim.setflag(); table[posx][posy] = true; break; }

				}
			}
			sim.print();
		}
	}
	return 0;
}

void Robot::turn(char dir)
{
	if(dir == 'R') {
		fid = (fid+1) % 4;
	}else if(dir == 'L') {
		fid = (fid -1 +4) % 4;
	}
}

void Robot::print() 
{
	cout << x << ' ' << y << ' ' << dir[fid];
	if(lost) cout << " LOST\n";
	else	 cout << '\n';
}
