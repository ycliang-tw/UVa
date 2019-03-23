#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

struct p{
    char alp;
    int cnt;
    p(){
        cnt = 0;
    };
};


bool cmp(struct p a, struct p b){
    if(a.cnt == b.cnt){
        return a.alp < b.alp;
    }else
        return a.cnt > b.cnt;
}


int main(){
    int cline = 0;
    while(cin >> cline){
        string input;
        getline(cin, input);
        vector<struct p>table(26);
        for(int i = 0; i < cline; i++){
            getline(cin, input);
            //printf("%s", input);
            for(int j = 0; input[j] != '\0'; j++){
                if(input[j] >= 'A' && input[j] <= 'Z'){
                    table[ input[j] - 'A' ].alp = input[j];
                    table[ input[j] - 'A' ].cnt++;
                }else if(input[j] >= 'a' && input[j] <= 'z'){
                    table[ input[j] - 'a' ].alp = input[j] - 'a' + 'A';
                    table[ input[j] - 'a' ].cnt++;
                }
            }
        }
        sort(table.begin(), table.end(), cmp);

        for(auto i : table){
            if(i.cnt > 0)
                cout << i.alp << " " << i.cnt << '\n';
        }

    }
    return 0;
}
