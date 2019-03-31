#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct SortNum
{
	int num, m;
	bool odd;
};

bool cmp(struct SortNum a, struct SortNum b)
{
	if(a.m == b.m) {
		if(a.odd && b.odd) {
			return a.num > b.num;
		} else if((!a.odd) && (!b.odd)) {
			return a.num < b.num;
		} else {
			return a.odd > b.odd;
		}
	}else {
		return a.m < b.m;
	}
	
}

int main()
{
	int num, mod;
	while( cin >> num >> mod ){
		if( num == 0 && mod == 0)	break;
		cout << num << " " << mod << '\n';
		vector<struct SortNum> arr(num);
		for(int i = 0; i < num; i++){
			cin >> arr[i].num;
			arr[i].m = arr[i].num % mod;
			arr[i].odd = (arr[i].num & 1);
		}
		sort(arr.begin(), arr.end(), cmp);
		for(int i = 0; i < arr.size(); i++){
			cout << arr[i].num << "\n";
		}
	}
	cout << "0 0\n";
	return 0;
}
