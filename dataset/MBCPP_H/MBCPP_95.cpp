    int n = lst.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int m = lst[i].size();
        if (ans == 0 || m < ans) {
            ans = m;
        }
    }
    return ans;
}