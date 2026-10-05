function ncrModp(n, r, p) {
    let C = new Array(r+1);
    let i;
    for(i = 0; i < r+1; i++){
        C[i] = 0;
    }
    C[0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = i; j > 0; j--) {
            C[j] = (C[j] + C[j-1]) % p;
        }
    }
    return C[r];
}
