DecisionTreeClassifier::Node* DecisionTreeClassifier::buildTree(const vector<vector<double>>& data, const vector<int>& labels) {
    if (data.empty()) return nullptr;
    Node* node = new Node();
    node->predictedClass = majorityClass(labels);
    if (calculateGini(labels) == 0.0) {
        node->isLeaf = true;
        return node;
    }
    node->featureIndex = 0; 
    node->threshold = 0.5; 
    node->left = buildTree(data, labels); 
    node->right = buildTree(data, labels); 
    return node;
}