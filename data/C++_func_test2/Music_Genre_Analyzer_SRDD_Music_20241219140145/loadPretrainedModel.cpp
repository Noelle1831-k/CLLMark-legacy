bool GenreClassifier::loadPretrainedModel(const string& modelPath) {
    ifstream file(modelPath.c_str());
    if (!file) {
        cerr << "Error: Unable to open model file." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<float> dataPoint;
        float value;
        while (iss >> value) {
            dataPoint.push_back(value);
        }
        if (!dataPoint.empty()) {
            trainingData.push_back(dataPoint);
            trainingLabels.push_back("Genre_" + to_string(trainingData.size())); 
        }
    }
    file.close();
    cout << "Model loaded successfully from " << modelPath << endl;
    return true;
}