#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(){
    int num;
    cin >> num;
    string line;
    getline(cin, line);
    map<string, int>table;
    for(int i = 0; i < num; i++){
        getline(cin, line);
        int pos = line.find_first_of(" ");
        line = line.substr(0, pos);
        //cout << "line == " << line << '\n';
        auto it = table.find(line);
        if(it != table.end()){  // found
            it->second += 1;
        }else{                  // not found
            table[line] = 1;
        }
    }
    for(auto i : table){
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}


