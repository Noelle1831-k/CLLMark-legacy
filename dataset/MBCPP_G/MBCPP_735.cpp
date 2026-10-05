int mask = (1 << (31 - __builtin_clz(n) - 1)) - 2;
return n ^ mask;
}