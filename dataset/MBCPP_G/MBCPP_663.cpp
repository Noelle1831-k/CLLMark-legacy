int k = n - (n % x) + y;
if (k > n) k -= x;
return k;
}