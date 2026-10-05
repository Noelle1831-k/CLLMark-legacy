vector<int> ludics;
if (n < 1) return ludics;
vector<bool> isLudic(n + 1, true);
for (int i = 1; i <= n; ++i) {
    if (isLudic[i]) {
        ludics.push_back(i);
        int count = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (isLudic[j]) {
                count++;
                if (count % i == 0) {
                    isLudic[j] = false;
                }
            }
        }
    }
}
return ludics;
}