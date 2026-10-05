int n = list.size();
    vector<int> indices(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int maxVal = INT_MIN, start = 0, end = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (!list[i].empty()) {
            minHeap.push({list[i][0], i});
            maxVal = max(maxVal, list[i][0]);
        }
    }

    while (true) {
        auto [minVal, idx] = minHeap.top();
        minHeap.pop();
        
        if (maxVal - minVal < end - start) {
            start = minVal;
            end = maxVal;
        }
        
        indices[idx]++;
        if (indices[idx] < list[idx].size()) {
            minHeap.push({list[idx][indices[idx]], idx});
            maxVal = max(maxVal, list[idx][indices[idx]]);
        } else {
            break;
        }
    }
    return {start, end};
}