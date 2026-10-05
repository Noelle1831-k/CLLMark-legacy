priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int n : num1) {
        minHeap.push(n);
    }
    for(int n : num2) {
        minHeap.push(n);
    }
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}