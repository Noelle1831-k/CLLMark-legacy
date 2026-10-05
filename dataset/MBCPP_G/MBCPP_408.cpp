vector<vector<int>> result;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
for (int i = 0; i < nums1.size() && i < k; ++i) {
    minHeap.push(make_tuple(nums1[i] + nums2[0], i, 0));
}
while (!minHeap.empty() && result.size() < k) {
    auto [sum, i, j] = minHeap.top();
    minHeap.pop();
    result.push_back({nums1[i], nums2[j]});
    if (j + 1 < nums2.size()) {
        minHeap.push(make_tuple(nums1[i] + nums2[j + 1], i, j + 1));
    }
}
return result;
}