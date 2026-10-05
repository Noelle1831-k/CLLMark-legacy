int result = 1;
for (int i = a + 1; i <= b; ++i) {
    result *= i;
    result %= 10;
}
return result;
}