//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		   int reverse = 0;
		   int originalNum = n;
		   
		   while(n>0){
		       int remainder = n%10;
		       reverse = reverse*10 + remainder;
		       n /= 10;
		   }
		   
		   if(reverse == originalNum)
		   {
		       return "Yes";
		   }
		   else
		   {
		       return "No";
		   }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends