#include <bits/stdc++.h>
using namespace std;

int main() 
{
	const int MAX_N = 122;

	int n, x,t;
  
	vector<long long int> dp(122, 0);
	vector<long long int>  count(122, 0);
  while(t--){
  //Storing Number of Characters in the Player's Array
	cin >> n;
 	char ith_character;
  //Taking Input of n characters accordingly and incrementing the frequency of that Number in a Vector
	while(n--) {
		
		cin >> ith_character;
		
		count[int(ith_character)]++;
	}

	dp[0] = 0;
	dp[1] = count[1];

	for (int i = 2; i < MAX_N; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + i*count[i]);
	}

	cout << dp[MAX_N - 1];
}
return 0;
}
