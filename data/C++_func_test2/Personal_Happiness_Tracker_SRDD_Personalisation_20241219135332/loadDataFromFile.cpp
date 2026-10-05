vector<string> loadDataFromFile(const string &fileName) {
        vector<string> data;
        ifstream inFile(fileName.c_str());
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                data.push_back(line);
            }
            inFile.close();
        } else {
            cerr << "Error: Unable to open file for reading." << endl;
        }
        return data;
    }