while (y != 0) {
    int temp = y;
    y = x % y;
    x = temp;
}
return x;
}