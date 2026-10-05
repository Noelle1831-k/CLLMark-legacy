string fraction = to_string(static_cast<long double>(p) / q);
int count = 0;
for (char c : fraction) {
    if (c == '.' || count >= n) continue;
    count++;
    if (count == n) return c - '0';
}
return -1;  // in case the nth digit does not exist within the decimal part.
}