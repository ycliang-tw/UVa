#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        int cmax = -1, ex, a1 = a, b1 = b;
        if(a > b){
            ex = a;
            a = b;
            b = ex;
        }
        for(int i = a; i <= b; i++){
            unsigned long long int tmp = i;
            int cycle = 1;
            while(tmp != 1){
                int odd = tmp & 1;
                if(odd){
                    tmp = 3*tmp+1;
                }else{
                    tmp /= 2;
                }
                cycle++;
            }
            if(cycle > cmax){
                cmax = cycle;
            }
        }
        cout << a1 << ' ' << b1 << ' ' << cmax << '\n';
    }
    return 0;
}
