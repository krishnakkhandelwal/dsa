#include<iostream>
using namespace std;

bool check(vector<int> &a,int left, int right){
    if(left>=right){
        return true;
    }
    if(a[left]!=a[right]){
        return false;
    }
    return check(a,left+1,right-1);

}


int main(){
    vector<int> k= {1,2,3,2,1};
    int n= k.size();
    bool ans = check(k,0,n-1);
    if(ans==true){
        cout<<"YES";
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;

}


