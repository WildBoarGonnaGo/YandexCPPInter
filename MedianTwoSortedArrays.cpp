//
//  MedianTwoSortedArrays.cpp
//  inter
//
//  Created by Locke Chantelle on 5/20/23.
//

#include <vector>

using namespace std;

public class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.empty()) {
            if (nums2.empty())
                return 0;
            else if (nums2.size() % 2)
                return nums2[(nums2.size() - 1) / 2];
            else
                return (nums2[nums2.size() - 1 / 2] + nums2[nums2.size() / 2]);
        }
        
    }
};
int main() {
    return 0;
}
