    int length = list1.size();
    int largest = 0;
    for (int i = 0; i < length; i++) {
        int value = list1[i];
        if (value > largest)
            largest = value;
    }
    return largest;
}