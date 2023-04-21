#include "bits/stdc++.h"
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    // create partition
    int partition = (n1 + n2 + 1) / 2;

    int start = 0, end = n1;
    int part1, part2;
    int leftX, leftY, rightX, rightY;

    while (start <= end) {
        part1 = (start + end) / 2;
        part2 = partition - part1;

        if (part1 == 0) {
            leftX = INT_MIN;
        } else {
            leftX = nums1[part1 - 1];
        }

        if (part2 == 0) {
            leftY = INT_MIN;
        } else {
            leftY = nums2[part2 - 1];
        }

        if (part1 == n1) {
            rightX = INT_MAX;
        } else {
            rightX = nums1[part1];
        }

        if (part2 == n2) {
            rightY = INT_MAX;
        } else {
            rightY = nums2[part2];
        }

        if (leftX <= rightY && leftY <= rightX) {
            if ((n1 + n2) % 2 == 0) {
                return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
            } else {
                return max(leftX, leftY);
            }
        } else if (leftX > rightY) {
            end = part1 - 1;
        } else {
            start = part1 + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median = " << median << endl;  // Output: Median = 2.00000
    return 0;
} 