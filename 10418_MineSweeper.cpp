#include <iostream>
using namespace std;

int main(){
	int row, col, Case=1;
	while(cin >> row >> col){
		if( row == 0 && col == 0)
			break;

		char input;
		int mine_field[101][101]={};
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cin >> input;
				if(input == '*'){
					mine_field[i][j] = -9;
					mine_field[i-1][j-1]++;
					mine_field[i-1][j]++;
					mine_field[i-1][j+1]++;
					mine_field[i][j-1]++;
					mine_field[i][j+1]++;
					mine_field[i+1][j-1]++;
					mine_field[i+1][j]++;
					mine_field[i+1][j+1]++;
				}
			}
		}
		cout << "Field #" << Case++ << ":\n";
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(mine_field[i][j] < 0)
					cout << "*";
				else
					cout << mine_field[i][j];
			}
			cout << endl;
		}
		
	}
	return 0;
}
