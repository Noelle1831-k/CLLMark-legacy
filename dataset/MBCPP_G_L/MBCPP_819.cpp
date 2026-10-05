vector<vector<int>> result;
vector<int> elements;
vector<int> counts;

if(lists.empty())
    return {{}, {}};

int current = lists[0];
int count = 1;

for (size_t i = 1; i < lists.size(); i++) {
    if (lists[i] == current) {
        count++;
    } else {
        elements.push_back(current);
        counts.push_back(count);
        current = lists[i];
        count = 1;
    }
}
elements.push_back(current);
counts.push_back(count);

result.push_back(elements);
result.push_back(counts);

return result;
}