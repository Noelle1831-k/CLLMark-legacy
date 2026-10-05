    int count = 0;
    for(int i = 0; i < 32; i++) {
        if((n1 & 1) != (n2 & 1))
            count++;
        n1 >>= 1;
        n2 >>= 1;
    }
    return count;
}