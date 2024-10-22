#include<bits/stdc++.h>
using namespace std;
// Knuth-Morris-Pratt (KMP) Algorithm is commonly used to solve problems involving string matching.
// It involves creating a LPS array.
// Problem 1: String and pattern matching
// Problem 2: Longest Prefix which is same as its Prefix (excluding itself)

vector<int> create_LPS(string&s){   // Function to create LPS of string s.
    int n=s.length();
    vector<int>lps(n);
    lps[0]=0;
    int low=0,i=1;
    while(i<n){
        if(s[low]==s[i])
            low+=1;
        else if(low!=0){
            low=lps[low-1];
            continue;
        }
        lps[i]=low;
        i++;
    }
    return lps;
}

int main(){
    string s="ababab";
    vector<int> lps=create_LPS(s);

    int max_len=lps[s.length()-1];
    string ans=s.substr(0,max_len);
    cout<<ans<<endl;
}