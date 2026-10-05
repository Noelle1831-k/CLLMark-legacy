unordered_set<int> kSet(k.begin(), k.end());
    for(int num : testTuple) {
        if(kSet.find(num) == kSet.end()) {
            return false;
        }
    }
    return kSet.size() == k.size();
}
}