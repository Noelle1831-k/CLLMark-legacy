priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}