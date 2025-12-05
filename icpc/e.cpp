#include <bits/stdc++.h>
using  namespace std;
/*
   so here, we basically have to pick some random color 
   as target, and match it with the other ones.

   since there are only 3 colors, the probabilty of each 
   would be 1/3, and the chances returning would be 3.

   optimal approach would be nothing  but 
   count the no of RGB. 
   choose a color out of them, may be that appears the most as target
   and change it.

   if we do that, the other two will minimal have 3 touches each {R,G,B}
   so we can derive something like 
   Ans = 3*(Total lighs - count of most freq color)

*/
int solve(){
	string s;cin>>s;
	int n=s.length();
	int red_count=0;
	int green_count =0;
	int blue_count =0;

	// we move to count the fre
	for(char c:s){
		if(c=='r') red_count++;
		if(c=='g') green_count++;
		if(c=='b') blue_count++;
	}
	// we need to find the value which occurs max 
	int mac=max({red_count,green_count,blue_count});
	int ans= 3*(n-mac);  // total - max 
	return ans;
}
int main(){
	int res=solve();
	cout<<res<<endl;
}
