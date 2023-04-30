//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false;
        
        for(auto word: wordList)
        {
            if(targetWord.compare(word) == 0)
            isPresent = true;
            myset.insert(word);
        }
        
        if(isPresent == false)
        return 0;
        
        queue<string> q;
        q.push(startWord);
        int depth = 0;
        
        while(!q.empty())
        {
            depth+=1;
            int lsize = q.size();
            while(lsize--)
            {
                string curr = q.front();
                q.pop();
                
                for(int i=0; i<curr.length(); i++)
                {
                    string temp = curr;
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if(curr.compare(temp) == 0)
                        continue;
                        if(temp.compare(targetWord) == 0)
                        return depth+1;
                        if(myset.find(temp) != myset.end())
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends