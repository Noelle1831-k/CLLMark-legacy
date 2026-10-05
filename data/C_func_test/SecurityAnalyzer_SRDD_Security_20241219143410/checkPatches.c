bool checkPatches() {
    printf("Checking for missing security patches...\n");
    return verifySoftwareVersions();
}