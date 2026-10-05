priority_queue<int, vector<int>, greater<int>> minHeap;
for(int num : num1) minHeap.push(num);
for(int num : num2) minHeap.push(num);
for(int num : num3) minHeap.push(num);
vector<int> result;
while(!minHeap.empty()) {
    result.push_back(minHeap.top());
    minHeap.pop();
}
return result;
}