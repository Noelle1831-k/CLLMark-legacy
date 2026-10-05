if (b == 0) return a;
return recurGcd(b, a % b);
}