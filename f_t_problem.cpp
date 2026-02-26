#include<iostream>
using namespace std;
int main(){
    string s= "ffffttttttt";
    int l=0;
    int r=s.size()-1;
    int low= INT_MAX;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(s[mid] == 't'){
            low=mid;
            r = mid - 1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<low;
}