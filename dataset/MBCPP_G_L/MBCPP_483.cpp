int n = 1, factorial = 1;
while (true) {
    factorial *= n;
    if (factorial % x == 0) return n;
    n++;
}
}