void LibraryInfo::displayLibraryInfo() {
    if (libraryData.empty()) {
        cout << "No library data available. Please load the library data first." << endl;
    } else {
        simulateLoading("Displaying library information...");
        cout << "Library content: " << libraryData << endl;
    }
}