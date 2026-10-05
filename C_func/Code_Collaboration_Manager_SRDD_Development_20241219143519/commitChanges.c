void commitChanges(VersionControl *vc) {
    printf("Committing changes...\n");
    strcpy(vc->commitMessage, "Committed changes");
}