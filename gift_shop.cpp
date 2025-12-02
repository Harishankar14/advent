#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std; 
typedef long long ll;
//part1 
/*condition of an ID to be invalid 
    ->55 (5 appears twice here)
    ->6464 (6464 appears twice here)
    kind of summary is that, it should not repeat more than once. 
    if it is -> consider it as invalid. 

    2. Second condition is that none of the id should be starting with 0.
    -> for example 0101  (this is a condition which satisfies both) 
*/

bool invalid(ll num){
	string a = to_string(num);
	int len = a.length();

	if (len %2 !=0){
		return false;
	}
	int split = len /2;
	string first=a.substr(0,split);
	string second= a.substr(split);
	return first == second;
}
int main() {
    // The input string from the problem
    string input;cin>>input;  //make sure it works for large for large input 

    ll totalSum = 0;
    stringstream ss(input);
    string segment;
    while (getline(ss, segment, ',')) {
        size_t dashpos = segment.find('-');
        string startstr = segment.substr(0, dashpos);
        string endstr = segment.substr(dashpos + 1);

        ll start = stoll(startstr);
        ll end = stoll(endstr);
        for (ll i = start; i <= end; ++i) {
            if (invalid(i)) {
                totalSum += i;
            }
        }
    }

    cout <<totalSum << endl;

    return 0;
}
