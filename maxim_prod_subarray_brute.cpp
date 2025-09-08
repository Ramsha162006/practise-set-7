#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProductSubarray(vector<int> &nums){
    int result = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            int prod = 1;
            for(int k = i; k <= j; k++){
                prod *= nums[k];
            }
            result = max(result, prod);
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,-3,0,0,4,-5};
    cout << maxProductSubarray(nums);
}
