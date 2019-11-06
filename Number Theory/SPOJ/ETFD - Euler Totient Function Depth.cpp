#include<bits/stdc++.h>
using namespace std;
int phi(int n){
    int result=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n=n/i;
            }
           result=result-(result/i);
        }
    }
    if(n>1) result=result-(result/n);
    return result;
}
map<int,int>mp;
vector<int>vec[21];
void pphi(){
    for(int i=1;i<=1000000;i++){
        int x=i,co=0;
            while(x!=1){
                if(mp[x]!=0){
                    mp[i]=co+mp[x];
                    vec[co+mp[x]].push_back(i);
                    break;
                }
                else{
                x=phi(x);
                co++;
                if(x==1)break;
            }
            }
            if(mp[i]==0){mp[i]=co;
           vec[co].push_back(i);
    }
    }
}
int main(){
    int n,a,b,c,result;
    pphi();
    cin>>n;
    while(n--){
        result=0;
        cin>>a>>b>>c;
        for(auto i=vec[c].begin();i!=vec[c].end();i++){
        if(*i>=a&&*i<=b)result++;
        }
        cout<<result<<endl;
    }
}
