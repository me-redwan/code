#include<bits/stdc++.h>
using namespace std;
vector<long int>vec;
void phi(){

    for(int i=0;i<=10001;i++){
        vec.push_back(i);
    }
    for(int i=2;i<=10001;i++){
        if(vec[i]==i){
            vec[i]=vec[i]-1;
            for(int j=i*2;j<=10001;j+=i){
                vec[j]=(vec[j]/i)*(i-1); //or vec[j] *= 1.0 - (1.0/i)
            }
        }
    }
}
int main(){
   phi();
   long long int n,a,b,c,k,result;
    cin>>n;
    while(n--){
       cin>>k;
       result=0;
       for(int i=0;i<=k;i++)result+=vec[i];
       cout<<result*result<<endl;
    }
}
