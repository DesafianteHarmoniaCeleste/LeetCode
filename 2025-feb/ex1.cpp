// LeetCode problem 1 - 02/01/2025
// Solution by Pedro Gasparelo Leme
// inspired by Rahul Varma

// an alternative solution using hash table in c++ (unordered_map)
// where we access a specific adress by its value, which is know, and get its position
// initialy i tried using bool since it uses less RAM space, but i had complications getting the position of the numbers in the vector
// the final ideia of using the unordered_map was inspired in Rahul Varma's Solution

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> numMap; // i chose unordered_map because of its O(1) search time complexity
        int n = nums.size();

        for(int i = 0; i < n; i++){ 
            int complement = target - nums[i]; // find the final answer by looking to its complement
            if(numMap.count(complement)){
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};
