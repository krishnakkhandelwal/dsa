#include<iostream>
using namespace std;
int main(){
    int m =4;
    int i=1;

    for(int j=0;j<32;j++){
        if((m & (i))==0){
            i= i<<1;
        }
        else{
            m =(m^i);
            break;
        }
    }
    cout<<m;
    return 0;

    
}
