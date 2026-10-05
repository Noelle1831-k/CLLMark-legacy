if(n == 0) return 0;
if(n < 0) return INT_MIN;
return 1 + max({maximumSegments(n - a, a, b, c), maximumSegments(n - b, a, b, c), maximumSegments(n - c, a, b, c)});
}