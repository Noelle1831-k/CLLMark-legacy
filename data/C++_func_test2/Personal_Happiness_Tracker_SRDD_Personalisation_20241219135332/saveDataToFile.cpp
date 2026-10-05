void saveDataToFile(const string &fileName, const vector<string> &data) {
        ofstream outFile(fileName.c_str());
        if (outFile.is_open()) {
            for (size_t i = 0; i < data.size(); i++) {
                outFile << data[i] << endl;
            }
            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    }