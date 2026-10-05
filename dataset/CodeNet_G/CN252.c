void checkGate(int b1, int b2, int b3) {
    if ((b1 == 1 && b2 == 1 && b3 == 0) || (b1 == 0 && b2 == 0 && b3 == 1)) {
        printf("Open\n");
    } else {
        printf("Close\n");
    }
}