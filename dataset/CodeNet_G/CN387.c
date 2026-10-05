int getMaxDressReuses(int A, int B) {
    if (A >= B) 
        return 1;
    else 
        return (B + A - 1) / A;
}