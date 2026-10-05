int count = 0;
for (int i = 0; i < (1 << (n + 1)); ++i) {
    if ((i & 1) && (i & (1 << n))) {
        ++count;
    }
}
return count;
}