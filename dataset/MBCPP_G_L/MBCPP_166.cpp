int count = 0;
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        if((a[i] ^ a[j]) % 2 == 0) {
            count++;
        }
    }
}
return count;
}