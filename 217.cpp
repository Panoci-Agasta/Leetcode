#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool containsDuplicate (vector<int>& nums);

int main(){
	vector<int> nums = {2,1,5,3,4};
	cout << containsDuplicate(nums) << "\n";
	return 0;
}


bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) 
                return true;
        }
        return false;
}
