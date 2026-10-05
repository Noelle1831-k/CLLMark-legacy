    int n = input.size();
    for (int i = 0; i < n; i++) {
        if (k != input[i].size()) {
            return "All tuples do not have same length";
        }
    }
    return "All tuples have same length";
}