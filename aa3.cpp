#include <bits/stdc++.h>
using namespace std;


void computeLPSArray(string & pat,int M,int *lps){
    int len=0;

    lps[0]=0;

    int i=0;
    while(i<M){
        if (pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if (len!=0) {
                len=lps[len-1];
            }
            else {
                lps[i]=0;
                i++;
            }
        }
    }
}

int KMPSearch(string & pat, string & txt ) {
    int M=pat.size();
    int N=txt.size();

    int lps[M];

    int res=-1;

    computeLPSArray(pat,M,lps);

    int i=0;
    int j=0;

    while(i<N){
        if (pat[j] == txt[i]){
            j++;
            i++;
        }

        if (j==M){
            int ans=i-j;
            res=max(res,ans);
            j=lps[j-1];
        }

        else if (i<N && pat[N]!=txt[i]) {
            if (j!=0) {
                j=lps[j-1];
            }
            else {
                i=i+1;
            }
        }
    }

    return res;

}

int main(){

    
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  


    int num;
    cin>>num;

    string str[num];

    for(int i=0;i<num;i++) {
        cin>>str[i];
    }

    string res;

    for(int i=0;i<num-1;i++) {
        if (i==0) {
            int index=KMPSearch(str[i],str[i+1]);
            if (index==-1) {
                for(auto x: str[i]){
                    res.push_back(x);
                }
                for(auto x: str[i+1]){
                    res.push_back(x);
                }
            }
            else {
                for(int j=0;j<=(index-1);j++) {
                    res.push_back(str[i][j]);
                }
                int sz=str[i].size();
                for(int j=sz-index;j<=str[i+1].size();j++) {
                    res.push_back(str[i+1][j]);
                }
                
            }
        }
        else {
            string res1;

            int index=KMPSearch(res,str[i+1]);
            if (index==-1) {
                for(auto x: res){
                    res1.push_back(x);
                }
                for(auto x: str[i+1]){
                    res1.push_back(x);
                }
            }
            else {
                for(int j=0;j<=(index-1);j++) {
                    res1.push_back(res[j]);
                }
                int sz=res.size();
                for(int j=sz-index;j<=str[i+1].size();j++) {
                    res1.push_back(str[i+1][j]);
                }
                
            }

            res=res1;

        }

    }

}
