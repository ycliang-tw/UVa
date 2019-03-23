#include <iostream>
using namespace std;

int main(){
    unsigned long long input;
    while(cin >> input && input){
        int ans = input;
        while(ans > 9){
            int tmp = 0;
            while(ans){
                tmp = tmp + ans%10;
                ans /= 10;
            }
            ans = tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}
