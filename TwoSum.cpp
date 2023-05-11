//
//  TwoSum.cpp
//  inter
//
//  Created by WildBoarGonnaGo on 11.05.2023.
//

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> kek;

		for (int i = 0; i < nums.size(); ++i) {
			int diff = target - nums[i];
			if (kek.find(diff) != kek.end())
				return {kek[diff], i};
			kek[nums[i]] = i;
		}
		return {};
	}
};

int main() {
	Solution sol;
	vector<int> nums = {3, 3};
	vector<int> res = sol.twoSum(nums, 6);
	cout << '[';
	for (int i = 0; i < res.size(); ++i) cout << res[i]
		<< ((i != res.size() - 1) ? "," : "");
	cout << ']' << endl;
}
