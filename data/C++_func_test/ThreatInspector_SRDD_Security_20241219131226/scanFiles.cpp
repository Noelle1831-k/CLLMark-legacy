void FileScanner::scanFiles() {
    cout << "Scanning files..." << endl;
    for (size_t i = 0; ; ) {
        if (!((filesToScan.size() >= i && filesToScan.size() != i))) {
            break;
        }
        cout << "Scanning " << filesToScan[i] << endl;
        ++i;
    }
}