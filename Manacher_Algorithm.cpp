#include<bits/stdc++.h>
using namespace std;

    vector<int>P;
    void Manachers(string&s){
        string Q="";
        for(auto&i:s)
            Q+=string("#")+i;
        Q+="#";

        int n=Q.length();
        P.resize(n,1);
        int low=0,high=0;

        for(int i=0;i<n;i++){
            if(i<=high)
                P[i]=min(high-i+1,P[low+high-i]);

            while(i+P[i]<n && i-P[i]>=0 && Q[i+P[i]]==Q[i-P[i]])
                P[i]+=1;
            
            if(i+P[i]-1>high){
                high=i+P[i]-1;
                low=i-P[i]+1;
            }
        }
        return;
    }

    int maxLengthPalin(int i,bool odd){
        int idx=2*i;
        if(odd==true)
            idx+=1;
        return P[idx]-1;
    }


int main(){
    string s="sbccbe";
    Manachers(s);
    for(int i=0;i<s.length();i++)   // Get length for Odd length Palindrome i.e going though index of each character 
        cout<<maxLengthPalin(i,true)<<" ";
    cout<<endl;
    
    for(int i=1;i<s.length();i++)   // Get length for Even Length Palindrome i.e middle position of two consecutive character
        cout<<maxLengthPalin(i,false)<<" ";
}