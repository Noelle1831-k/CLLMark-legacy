void scan_filesystem() {
    printf("Scanning filesystem for malware...\n");
    log_event("Filesystem scan initiated.");
    const char *files[] = {"file1.txt", "file2.txt", "infected_file.txt", "file3.txt", "file4.txt"};
    int total_files = sizeof(files) / sizeof(files[0]);
    bool threat_detected = false;
    for (int i = 0; i < total_files; i++) {
        printf("Scanning file: %s...\n", files[i]);
        if (detect_virus_signature(files[i])) {
            printf("Threat detected in file: %s\n", files[i]);
            threat_detected = true;
            log_event("Threat detected during scan.");
        } else {
            printf("File %s is clean.\n", files[i]);
        }
    }
    if (!threat_detected) {
        printf("No threats detected in the filesystem.\n");
        log_event("Filesystem scan completed. No threats found.");
    }
}