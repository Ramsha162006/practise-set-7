#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProductSubarray(vector<int> &nums){
    int result = nums[0];   // start with first element
    for(int i = 0; i < nums.size(); i++){
        int p = nums[i];    // product starts at nums[i]
        for(int j = i+1; j < nums.size(); j++){
            result = max(result, p); // check before extending
            p *= nums[j];            // extend product
        }
        result = max(result, p);     // also check last product
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,-3,0,0,4,-5};
    cout << maxProductSubarray(nums);
}