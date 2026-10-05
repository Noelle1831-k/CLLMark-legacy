    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == x[0]) {
            count++;
        }
        if (str[i] == x[1] && str[i-1] != x[1]) {
            count++;
        }
    }
    int n = 10;
    int repititions = n / str.size();
    count = count * repititions;
    int l = n % str.size();
    for (int i = 0; i < l; i++) {
        if (str[i] == x[0]) {
            count++;
        }
    }
    return count;
}