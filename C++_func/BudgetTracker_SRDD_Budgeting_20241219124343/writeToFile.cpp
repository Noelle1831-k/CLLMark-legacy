static void writeToFile(const string& filename, const string& data) {
        ofstream file(filename);
        if (file.is_open()) {
            file << data;
            file.close();
        } else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }