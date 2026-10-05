int gcd = __gcd(x, y);
int count = 0;
for (int i = 1; i <= gcd; i++) {
    if (gcd % i == 0) {
        count++;
    }
}
return count;
}