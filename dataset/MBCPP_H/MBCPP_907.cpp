    vector<int> arr = {1, 3, 7, 9, 13, 15, 21, 25, 31, 33};
    vector<int> result = vector<int>();
    for (auto v : arr) {
        if (n > 0) {
            result.push_back(v);
            n--;
        } else {
            break;
        }
    }
    return result;
}