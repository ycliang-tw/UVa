#include <iostream>
#include <vector>
using namespace std;

/* 
 * Pseudocode of KMP algorithm by "Introduction to Algorithms 2nd edition" p.926
 * 
 * KMP-MATCHER(T, P)
 * 1 n   <- length[T]
 * 2 m   <- length[P]
 * 3 pi  <- COMPUTE-PREFIX-FUNCTION(P)
 * 4 q   <- 0                                  // Number of characters matched
 * 5 for i <- 1 to n                           // Scan the text from left to right
 * 6     do while q > 0 and P[q+1] != T[i]
 * 7        do q <- pi[q]                      // Next character does not match
 * 8     if P[q+1] == T[i]
 * 9        then q <- q + 1                    // Next character matches
 *10     if q == m                             // Is all of P matched?
 *11        then print "Pattern occurs with shift" i-m
 *12        q <- pi[q]                         // Look for the next match
 *
 * COMPUTE-PREFIX-FUNCTION(P)
 * 1 m     <- length[P]
 * 2 pi[1] <- 0
 * 3 k     <- 0
 * 4 for q <- 2 to m
 * 5     do while k > 0 and P[k+1] != P[q]
 * 6        do k <- pi[k]
 * 7     if P[k+1] == P[q]
 * 8        then k <- k + 1
 * 9     pi[q] = k
 *10 return pi 
 *
 */

/* 
 * pi array stores the length of the proper prefix suffix 
 * ex. pi[5] stores the length of the proper prefix suffix of P5 (the first 5 char of pattern)
 * and the length equals the index of the previous same character +1,
 * means that length will be as same as the index of the next chatacter to be compared with,
 * so we could use the array to move to the position we want to compare.
 *
 *      -----------------------------------
 *      | idx | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 
 *      -----------------------------------
 * ex.  | str | a | b | a | b | a | b | c | ,  'b'  ==>  pi[5] == 4 == 3 + 1 == idx + 1 == jdx , str[3] ==> the previous 'b', the next character to do the comparison str[jdx] 'a'
 *      ----------------------------------- ,  so when we have a mismatch at 'c'(idx == 6), meaning that we still are matching until 'b'(idx == 5),
 *      | pi  | 0 | 0 | 1 | 2 | 3 | 4 | 0 | ,  the next character we want to compared with is the character next to the previous 'b' (idx == 3),
 *      ----------------------------------- ,  hence we move our index "q = pi[q- 1]" (q = pi[6-1])
 *
 * 
 *
 */

void KMP_matcher(string text, string pattern, vector<int>&prefix) 
{
	int tlen = text.length();
	int plen = pattern.length();
	int q    = 0;
	for(int i = 0; i < tlen; i++){
		while(q > 0 && pattern[q] != text[i]){
			q = prefix[q-1];
		}
		if(pattern[q] == text[i]){
			q++;
		}
		if(q == plen){
			cout << "found pattern at " << i - q + 1 << '\n';
			q = prefix[q-1];
		}
	}
}

vector<int> compute_prefix_function(string pattern) 
{
	int len = pattern.length();
	int k   = 0, q = 0;                            // k -> length of the proper prefix suffix, also the index of the next character
	vector<int>prefix(len);	

	prefix[0] = 0;

	for(q = 1; q < len; q++){
		while(k > 0 && pattern[k] != pattern[q]){ // k has to be >0 to do "k = prefix[k-1]", cause k represents the next character's index,
			k = prefix[k-1];                      // so the least k can be is 0
		}
		if(pattern[k] == pattern[q]){
			k++;
		}
		prefix[q] = k;
	}
	return prefix;
}

int main()
{
	string text("abaababaacacbababaacbabababaacbc");
	string pattern("ababaac");
	string ans("ans should be 3, 13, 23");
	
	cout << ans << '\n';

	vector<int>prefix( compute_prefix_function( pattern ) );
	KMP_matcher(text, pattern, prefix);
	
	for(int i = 0; i < prefix.size(); i++){
		cout << prefix[i] << '\n';
	}

	return 0;
}
