unordered_map<int, int> frequency_map;
for (const auto& list : nums) {
    for (int num : list) {
        frequency_map[num]++;
    }
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

for (const auto& entry : frequency_map) {
    min_heap.push({entry.second, entry.first});
    if (min_heap.size() > k) {
        min_heap.pop();
    }
}

vector<int> result;
while (!min_heap.empty()) {
    result.push_back(min_heap.top().second);
    min_heap.pop();
}

reverse(result.begin(), result.end());
return result;
}