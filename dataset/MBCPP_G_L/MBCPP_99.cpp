string binary = "";
while (n > 0) {
    binary = char((n % 2) + '0') + binary;
    n /= 2;
}
return binary;
}