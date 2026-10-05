int mask = 0;
for (int i = 0; i < 8 * sizeof(n); i += 2) {
    mask |= (1 << i);
}
return n ^ mask;
}