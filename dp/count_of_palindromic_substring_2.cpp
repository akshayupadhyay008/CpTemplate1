#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001]; // 2D matrix
bool isPal(string s, int i, int j)
{
	// Base condition
	if (i > j)
		return 1;

	// check if the recursive tree
	// for given i, j
	// has already been executed
	if (dp[i][j] != -1)
		return dp[i][j];

	// If first and last characters of
	// substring are unequal
	if (s[i] != s[j])
		return dp[i][j] = 0;

	// memoization
	return dp[i][j] = isPal(s, i + 1, j - 1);
}

int countSubstrings(string s)
{
	memset(dp, -1, sizeof(dp));
	int n = s.length();
	int count = 0;

	// 2 for loops are required to check for
	// all the palindromes in the string.
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// Increment count for every palindrome
			if (isPal(s, i, j))
				count++;
		}
	}
	// return total palindromic substrings
	return count;
}

// Driver code
int main()
{

	string s = "abbaeae";

	cout << countSubstrings(s);

	//"bb" , "abba" ,"aea", "eae" are
	// the 4 palindromic substrings.

	return 0;
}
