int t = 1, index = 1;
while (true) {
    int numDigits = log10(t * (t + 1) / 2) + 1;
    if (numDigits == n) return index;
    t++;
    index++;
}
}