    if(list1.size() == 0) return 0;
    int j = 0;
    while(j < list1.size()) {
        if(list1[j] % 2 == 0) return list1[j];
        else if(list1[j] % 2 == 1) j++;
    }
    return 0;
}