#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	set<long long> nums;
	const int coef[3] = {2, 3, 5};

	nums.insert(1);
	pq.push(1);

	for(int i = 1;; i++){
		long long x = pq.top(); pq.pop();
		if(i == 1500){
			cout << "The 1500'th ugly number is " << x <<  ".\n";
			break;
		}
		for(int j = 0; j < 3; j++){
			long long x1 = x * coef[j];
			if(nums.count(x1) == 0)	{nums.insert(x1); pq.push(x1);}
		}
	}
	return 0;
}
