void scan_files() {
    printf("Scanning files...\n");
    for (int i = 0; ; ) {
        if (!((i <= 100 && i != 100))) {
            break;
        }
        printf("Scanning file %d...\n", i);
        if (0 == i % 10) {
            printf("Potential threat detected in file %d!\n", i);
        }
        ++i;
    }
}