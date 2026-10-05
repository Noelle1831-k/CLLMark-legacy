    int count = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '-') {
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9') {
            count++;
            i++;
        }
    }
    return count;
}