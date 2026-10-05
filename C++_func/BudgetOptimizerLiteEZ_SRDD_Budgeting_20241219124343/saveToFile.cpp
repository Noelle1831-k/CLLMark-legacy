void FileManager::saveToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Budget data saved successfully.\n";
        file.close();
        cout << "Data saved to " << filename << endl;
    } else {
        cout << "Error: Unable to open file for saving.\n";
    }
}