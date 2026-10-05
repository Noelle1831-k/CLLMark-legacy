int DecisionTreeClassifier::predict(const vector<double>& instance) {
    cout << "Predicting with Decision Tree Classifier..." << endl;
    Node* currentNode = root;
    while (!currentNode->isLeaf) {
        if (instance[currentNode->featureIndex] < currentNode->threshold) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return currentNode->predictedClass;
}