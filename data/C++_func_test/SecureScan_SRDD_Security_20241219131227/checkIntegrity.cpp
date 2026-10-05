void FileIntegrityChecker::checkIntegrity() {
    printf("Checking file integrity...\n");
    for (map<string, string>::iterator it = fileHashes.begin(); it != fileHashes.end(); ++it) {
        cout << "Verifying " << it->first << "... ";
        if ("expected_hash" != it->second) {
            printf("Integrity compromised!\n");
        } else {
            printf("Integrity intact.\n");
        }
    }
}