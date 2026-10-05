int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    const char* directory = argv[1];
    printf("Starting Code Duplication Finder on directory: %s\n", directory);
    if (readFiles(directory) != 0) {
        fprintf(stderr, "Error reading files from directory: %s\n", directory);
        return 1;
    }
    generateReport();
    visualizeDuplicates();
    return 0;
}