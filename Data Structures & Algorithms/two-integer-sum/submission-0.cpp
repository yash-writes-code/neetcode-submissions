class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> freq;
        int n = nums.size();

        for(int i =0;i < n ; i++){
            int elem = nums[i];
            int complement = target - elem;

            if(freq.find(complement) != freq.end()){
                return {freq[complement], i};
            }
            else if(freq.find(elem) == freq.end()){
                freq[elem]= i;
            }
        }
        return {-1,-1};

    }
};
