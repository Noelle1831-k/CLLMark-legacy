    vector<int> ans;
    if (2 * l <= r) {
        ans.push_back(l);
        ans.push_back(2 * l);
    } else {
        ans.push_back(-1);
    }
    return ans;
}