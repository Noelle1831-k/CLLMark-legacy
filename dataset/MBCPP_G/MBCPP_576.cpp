for(int i = 0; i <= n - m; i++) {
    int j;
    for(j = 0; j < m; j++) {
        if(a[i + j] != b[j]) {
            break;
        }
    }
    if(j == m) {
        return true;
    }
}
return false;
}