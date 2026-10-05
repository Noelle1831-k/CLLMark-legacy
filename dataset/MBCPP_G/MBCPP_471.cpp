int product = 1;
for (int i = 0; i < lens; i++) {
    product = (product * (arr[i] % n)) % n;
}
return product % n;
}