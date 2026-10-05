    int temp = n;
    int res = 0;
    int count = 0;
    while(temp > 0) {
        if(count % 2 == 1) {
            res |= (1 << count);
        }
        count++;
        temp >>= 1;
    }
    return (n | res);
}