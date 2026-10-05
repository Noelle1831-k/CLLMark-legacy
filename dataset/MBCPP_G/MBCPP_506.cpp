int result = 1;
for (int i = 0; i < k; i++) {
    result *= (n - i);
}
return result;
}