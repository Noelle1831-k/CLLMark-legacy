static string readFromFile(const string& filename) {
        ifstream file(filename);
        stringstream buffer;
        if (file.is_open()) {
            buffer << file.rdbuf();
            file.close();
        } else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
        return buffer.str();
    }