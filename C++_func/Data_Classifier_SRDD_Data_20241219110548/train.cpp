void DecisionTreeClassifier::train(const vector<vector<double>>& data) {
    cout << "Training Decision Tree Classifier..." << endl;
    vector<int> labels(data.size(), 0); 
    root = buildTree(data, labels);
}