void Scanner::scanFiles() {
    cout << "Scanning files for threats..." << endl;
    vector<string> files = {"file1.txt", "file2.exe", "file3.dll"};
    for (size_t i = 0; i < files.size(); i++) {
        cout << "Scanning " << files[i] << "... ";
        if (rand() % 2 == 0) {
            cout << "Threat detected!" << endl;
        } else {
            cout << "No threats found." << endl;
        }
    }
}