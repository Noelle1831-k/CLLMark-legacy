int result = 1; 
for (int i = 1; i <= n; ++i) {
    result = (result * i) / __gcd(result, i);
}
return result;
}