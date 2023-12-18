#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int maxProductDifference(vector<int>& nums) {
  int len = nums.size();
  sort(nums.begin(),nums.end());
  return nums[len-2]*nums[len-1] - nums[0]*nums[1];
}

int main() { 
  vector<int> nums = {5,7,5,8,6,3,2,1,4,9};
  
  cout << maxProductDifference(nums) << endl;

  return 0; 
}


