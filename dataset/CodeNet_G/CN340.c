void checkRectangle(int e1, int e2, int e3, int e4) {
    int edges[4] = {e1, e2, e3, e4};
    int i, j, temp;
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (edges[i] > edges[j]) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    if ((edges[0] == edges[1]) && (edges[2] == edges[3])) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}