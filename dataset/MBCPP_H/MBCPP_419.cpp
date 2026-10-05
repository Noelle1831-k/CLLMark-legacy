    int n = list1.size();
    if (n == 0) {
        return 0;
    }
    vector<double> res;
    for (int i = 0; i < n; i++) {
        res.push_back(round(list1[i]));
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += res[i];
    }
    return sum * n;
}