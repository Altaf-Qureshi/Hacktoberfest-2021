/*Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.*/

//Time complexity:-O(|s1|*|s2|)


#include <bits/stdc++.h>
using namespace std;
int shortestCommonSupersequence(string s1, string s2, int x, int y)
    {
        
        int t[x+1][y+1];
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0||j==0)
                t[i][j]=0;
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return x+y-t[x][y];
        
    }
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
      int ans=shortestCommonSupersequence(s1,s2,s1.length(),s2.length());
      cout<<ans<<endl;
        
    }

    return 0;}
