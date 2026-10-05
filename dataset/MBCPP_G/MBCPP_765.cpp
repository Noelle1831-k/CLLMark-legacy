int count = 0, num = 1;
while (count < n) {
    int k = num;
    while (k % 2 == 0) {
        k /= 2;
    }
    if (k != 1) {
        count++;
    }
    num++;
}
return num - 1;
}