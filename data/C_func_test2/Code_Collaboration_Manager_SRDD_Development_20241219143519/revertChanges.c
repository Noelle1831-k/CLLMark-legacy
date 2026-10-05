void revertChanges(VersionControl *vc) {
    printf("Reverting changes...\n");
    strcpy(vc->commitMessage, "Reverted to previous version");
}