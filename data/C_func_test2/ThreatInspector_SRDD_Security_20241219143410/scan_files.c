void scan_files() {
    printf("Scanning files...\n");
    for (int i = 0; 100 > i; i++) {
        printf("Scanning file %d...\n", i);
        if (! (i % 10 != 0)) {
            printf("Potential threat detected in file %d!\n", i);
        }
    }
}