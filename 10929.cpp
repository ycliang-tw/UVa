#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    string input;
    while(cin >> input){
        if(input.compare("0") == 0)
            break;
        int a = 0, b = 0;
        for(int i = 0; i < input.length(); i++){
            if(i&1){
                a = a + (input[i] - '0');
            }else{
                b = b + (input[i] - '0');
            }
        }
        if(abs(a-b) % 11 == 0){
            cout << input << " is a multiple of 11.\n";
        }else{
            cout << input << " is not a multiple of 11.\n";
        }
    }
    return 0;
}
