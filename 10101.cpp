#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
    unsigned long long input;
    int arr[4] = {10, 100, 100, 100};
    string sarr[4] = {" shata", " hajar", " lakh", " kuti"};
    int ncase = 1;
    while(cin >> input){
        if(input == 0){
            cout << setw(4) << ncase++ << ". 0\n";
            continue;
        }
        stringstream ss;
        string tmpstr, ans;
        int tmpnum, j = 0;
        tmpnum = input%100;
        if(tmpnum != 0){
            ss << tmpnum;
            ss >> ans;
            ans.insert(0, " ");
        }
        input /= 100;
        while(input){
            tmpnum = input % arr[j%4];
            if(tmpnum != 0){
                ans.insert(0, sarr[j%4]);
                stringstream s1;
                string t1;
                s1 << tmpnum;
                s1 >> t1;
                ans.insert(0, t1);
                ans.insert(0, " ");
                //cout << "tmpnum == " << tmpnum << ", string == " << t1 << ", unit == " << sarr[j%4] << '\n';
            }else if(j == 3){
                //cout << "j==" << j << ", input = " << input << ", tmpnum == " << tmpnum << '\n';
                ans.insert(0, " kuti");
            }

            input /= arr[j%4];
            j++;
        }
        cout << setw(4) << ncase++ << "." << ans << '\n';
    }

    return 0;
}
