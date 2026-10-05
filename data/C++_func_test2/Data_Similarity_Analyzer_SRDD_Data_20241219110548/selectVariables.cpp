void UserInterface::selectVariables() {
    string method;
    cout << "Select similarity method (jaccard/cosine): ";
    cin >> method;
    vector<vector<string>> data;
    for (const auto& dataset : datasets) {
        data.push_back(dataset.getData()[0]); 
    }
    similarityMatrix.generateMatrix(data, method);
}