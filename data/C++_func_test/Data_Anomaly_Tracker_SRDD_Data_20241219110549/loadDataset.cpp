void DatasetManager::loadDataset() {
    string fileName;
    cout << "Enter the dataset file name: ";
    scanf("%s", &fileName);
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }
    string line;
    string cell;
    
    bool isHeader = true;
    while (getline(file, line)) {
        stringstream lineStream(line);
        vector<double> row;
        if (isHeader) {
            isHeader = false;
            while (getline(lineStream, cell, ',')) {
                headers.push_back(cell);
            }
            continue;
        }
        while (getline(lineStream, cell, ',')) {
            row.push_back(stod(cell));
        }
        dataset.push_back(row);
    }
    cout << "Dataset loaded successfully!" << endl;
}