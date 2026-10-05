int main() {
    int w, i, k = 0;
    char res[20];
    scanf("%d", &w);
    while ( w > 0 ) {
	switch ( w%3 ) {
	case 0:
	    res[k++] = '0';
	    w /= 3;
	    break;
	case 1:
	    res[k++] = '+';
	    w /= 3;
	    break;
	case 2:
	    res[k++] = '-';
	    w = w/3 + 1;
	    break;
	}
    }
    for ( i=k-1; i>=0; --i ) printf("%c", res[i]);
    printf("\n");
    return 0;
}
