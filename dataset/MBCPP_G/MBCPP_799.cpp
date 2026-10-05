int numBits = sizeof(n) * 8;
return (n << d) | (n >> (numBits - d));
}