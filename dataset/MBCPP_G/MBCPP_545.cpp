int numberOfBits = sizeof(n) * 8;
int firstBitMask = 1 << (numberOfBits - 1);
int lastBitMask = 1;
return n ^ (firstBitMask | lastBitMask);
}