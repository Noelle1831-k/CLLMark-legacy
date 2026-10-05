sort(tuples.begin(), tuples.end(), [](const vector<int>& a, const vector<int>& b) {
    return a.back() < b.back();
});
return tuples;
}