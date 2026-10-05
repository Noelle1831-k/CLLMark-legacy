    for (size_t i = 1; i < list1.size(); ++i) {
        if (list1[i] < list1[i - 1]) {
            return false;
        }
    }
    return true;
}