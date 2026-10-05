set<int> set1(li1.begin(), li1.end());
set<int> set2(li2.begin(), li2.end());
vector<int> result;

for (int num : li1) {
    if (set2.find(num) == set2.end()) {
        result.push_back(num);
    }
}

for (int num : li2) {
    if (set1.find(num) == set1.end()) {
        result.push_back(num);
    }
}

return result;
}