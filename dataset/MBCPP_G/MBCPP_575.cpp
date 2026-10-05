int count = 0;
for (int i = l; i <= r; ++i) {
    if (i % n != 0) {
        ++count;
        if (count == a) {
            return i;
        }
    }
}
return -1;
}