if (n == 0) return 0;
int msb = 0;
while (n != 0) {
    n = n >> 1;
    msb++;
}
return 1 << (msb - 1);
}