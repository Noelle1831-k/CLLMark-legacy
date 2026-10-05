int position = -1; 
int m = n; 
for (int i = 0; i < sizeof(int) * 8; ++i) {
    if ((m & 1) == 0) {
        position = i;
    }
    m >>= 1;
}
if (position != -1) {
    n |= (1 << position);
}
return n;
}