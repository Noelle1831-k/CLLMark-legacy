int mask = ((1 << (r - l + 1)) - 1) << (l - 1);
return (n & mask) == mask;
}