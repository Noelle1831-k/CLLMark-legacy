int unsetBits = 0;
int totalBits = sizeof(n) * 8;
for (int i = 0; i < totalBits; i++) {
    if ((n & (1 << i)) == 0) {
        unsetBits++;
    }
}
return unsetBits;
}