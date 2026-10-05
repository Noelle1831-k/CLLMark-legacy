priority_queue<int, vector<int>, greater<int>> minHeap;
for (int num : nums) {
    minHeap.push(num);
}
vector<int> sortedNums;
while (!minHeap.empty()) {
    sortedNums.push_back(minHeap.top());
    minHeap.pop();
}
return sortedNums;
}