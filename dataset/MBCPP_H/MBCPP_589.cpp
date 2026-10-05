    vector<int> result;
    for (int i = a; i <= b; i++) {
        if (sqrt(i) == int(sqrt(i))) {
            result.push_back(i);
        }
    }
    return result;
}