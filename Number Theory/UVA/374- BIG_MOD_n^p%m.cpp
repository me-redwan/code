//find (P power N) % M
//UVA - 374 - Big Mod

#include<bits/stdc++.h>
using namespace std;
long long int po(long long int a,long long int b,long long MOD){
    if(b==0)return 1;
    if(b%2==0){
        long long int res=po(a,b/2,MOD); //recursion for even power.. means we can devide even power to half (ex 2^30 = 2^15 *2^15) __ oviously moded my MOD;
        return ((res%MOD)*(res%MOD))%MOD;
    }
    else return ((a%MOD)*(po(a,b-1,MOD)%MOD))%MOD; //recursion for odd power..(ex: 2^25 = 2* 2^24)..p*p^(n-1) __ oviously moded my MOD;
}
int main(){
   long long int p,n,m,res;
   while(cin>>p>>n>>m){
        res=po(p,n,m);
        cout<<"(p^n)%m is : "<<res<<endl;
   }
}
