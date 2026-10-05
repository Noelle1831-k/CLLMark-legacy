if (b == 0) return a == c; 
int diff = c - a;
return (diff % b == 0) && (diff / b >= 0);
}