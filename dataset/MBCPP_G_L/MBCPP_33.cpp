string binary = "";
while (n > 0) {
    binary = to_string(n % 2) + binary;
    n /= 2;
}
return binary.empty() ? "0" : binary;
}