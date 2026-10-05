int gcd = __gcd(a, b); 
int result = 0; 
for (int i = 1; i <= gcd; ++i) { 
    if (gcd % i == 0) 
        result += i; 
} 
return result;
}