unordered_map<char, int> freq;
priority_queue<pair<int, char>> maxHeap;
for (char c : s) {
    freq[c]++;
}
for (auto it : freq) {
    maxHeap.push({it.second, it.first});
}
string result;
pair<int, char> prev = {-1, '#'};
while (!maxHeap.empty()) {
    auto [count, charac] = maxHeap.top();
    maxHeap.pop();
    result.push_back(charac);
    if (prev.first > 0) {
        maxHeap.push(prev);
    }
    prev = {count - 1, charac};
}
if (result.length() != s.length()) return "";
return result;
}