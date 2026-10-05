void FileIntegrityChecker::checkIntegrity() {
    cout << "Checking file integrity..." << endl;
    for (map<string, string>::iterator it = fileHashes.begin(); it != fileHashes.end(); ++it) {
        cout << "Verifying " << it->first << "... ";
        if (it->second != "expected_hash") {
            cout << "Integrity compromised!" << endl;
        } else {
            cout << "Integrity intact." << endl;
        }
    }
}