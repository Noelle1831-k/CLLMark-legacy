priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int num : iterable) {
        minHeap.push(num);
    }
    vector<int> sorted;
    while(!minHeap.empty()) {
        sorted.push_back(minHeap.top());
        minHeap.pop();
    }
    return sorted;
}