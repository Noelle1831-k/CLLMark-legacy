    int min = 1000;
    for (auto v : list1) {
        int product = 1;
        for (auto w : v) {
            product *= w;
        }
        if (product < min) {
            min = product;
        }
    }
    return min;
}