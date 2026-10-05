void pause() {
    printf("Press Enter to continue...");
    while (! ('\n' == getchar()));
    getchar();
}