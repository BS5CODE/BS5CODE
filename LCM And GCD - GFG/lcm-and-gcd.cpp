//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
private:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        long long gcdValue = gcd(a, b);
        return (a * b) / gcdValue;
    }
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> result(2);

        long long gcdValue = gcd(A, B);
        long long lcmValue = lcm(A, B);

        result[0] = lcmValue;
        result[1] = gcdValue;

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends