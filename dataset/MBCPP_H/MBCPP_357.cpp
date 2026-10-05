    int max = 0;
    for (vector<int> t : testList) {
        int val = t[0];
        for (int i : t) {
            val = val > i ? val : i;
        }
        if (val > max) {
            max = val;
        }
    }
    return max;
}