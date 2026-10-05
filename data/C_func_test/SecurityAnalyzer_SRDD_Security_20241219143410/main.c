int main() {
    initialize();
    if (!scanNetwork()) {
        printf("Error: Network scan failed. Continuing with remaining scans...\n");
    }
    if (!scanSystem()) {
        printf("Error: System scan failed. Continuing with remaining scans...\n");
    }
    if (!checkPatches()) {
        printf("Error: Patch check failed. Continuing with remaining tasks...\n");
    }
    generateReport();
    printf("Security analysis complete.\n");
    return 0;
}