vector<int> result;
transform(nums1.begin(), nums1.end(), nums2.begin(), back_inserter(result), [](int a, int b) { return a - b; });
return result;
}