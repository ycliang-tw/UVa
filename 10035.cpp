#include <iostream>
using namespace std;

int main(){
    unsigned long long a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;

        int carry = 0, ccount = 0;
        while(a || b){
            if(carry + a%10 + b%10 > 9){
                ccount++;
                carry = 1;
            }else{
                carry = 0;
            }
            a/=10;
            b/=10;
        }
        if(ccount){
            if(ccount == 1){
                cout << ccount << " carry operation.\n";
            }else
                cout << ccount << " carry operations.\n";
        }else
            cout << "No carry operation.\n";
    }
    return 0;
}
