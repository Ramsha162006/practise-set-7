#include<iostream>
#include<vector>
using namespace std;

int countPairs(vector<int> &a,int n){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i]>2*a[j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<int> a = {4,1,2,3,1};
    int n = 5;
    int cnt = countPairs(a,n);
    cout<<cnt<<endl;
}