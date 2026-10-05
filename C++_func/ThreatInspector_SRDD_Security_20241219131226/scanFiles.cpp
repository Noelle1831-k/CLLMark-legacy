void FileScanner::scanFiles() {
    cout << "Scanning files..." << endl;
    for (size_t i = 0; i < filesToScan.size(); ++i) {
        cout << "Scanning " << filesToScan[i] << endl;
    }
}