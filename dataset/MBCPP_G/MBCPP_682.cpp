vector<int> result(nums1.size());
transform(nums1.begin(), nums1.end(), nums2.begin(), result.begin(), [](int a, int b) { return a * b; });
return result;
}