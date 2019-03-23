#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    string str = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    map<char, char>mapping;
    string line;
    for(int i = 2; i < str.length(); i++){
        mapping[str[i]] = str[i-2];
    }
    while(getline(cin, line)){
            //cout << "line == " << line << '\n';
        for(int i = 0; i < line.length(); i++){
            if(line[i] >= 'A' && line[i] <= 'Z')
                line[i] = line[i] - 'A' + 'a';
            auto it = mapping.find(line[i]);
            if(it != mapping.end()){
                cout << it->second;
            }else{
                cout << line[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
