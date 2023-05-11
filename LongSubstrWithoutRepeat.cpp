//
//  LongSubstrWithoutRepeat.cpp
//  inter
//
//  Created by WildBoarGonnaGo on 11.05.2023.
//

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int m = 0;
		vector<int> alpha(128);

		for (int i = 0, st = 0; i < s.length(); ++i) {
			++alpha[s[i]];
			while (alpha[s[i]] > 1)
				--alpha[s[st++]];
			m = max<int>(m, i - st + 1);
		}
		return m;
	}
};
