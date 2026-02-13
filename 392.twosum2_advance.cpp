#include <iostream>
using namespace std;
int main(){
    vector<int> k = {10,20, 20, 20, 90, 90, 100};
    int target=110;
    int m= k.size()-1;
    int n=0;
    int count=0;
    int leftcount=0;
    int rightcount=0;
    while(n<m){
        if(k[n]+k[m] > target) m--;
        else if(k[n]+k[m] < target) n++;
        
        else{
            int leftVal = k[n];
            int leftCount = 0;
            while(n <= m && k[n] == leftVal){
                leftCount++;
                n++;
            }
            
            int rightVal = k[m];
            int rightCount = 0;
            while(m >= n && k[m] == rightVal){
                rightCount++;
                m--;
            }

            count += leftCount * rightCount;
        }
    }
    cout<<count;
    return 0;
}




