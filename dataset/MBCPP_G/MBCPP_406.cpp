int count = __builtin_popcount(x);
return (count % 2 == 0) ? "Even Parity" : "Odd Parity";
}