void MLModel::train(const vector<vector<float>>& features, const vector<float>& labels) {
    size_t featureCount = features[0].size();
    weights.assign(featureCount, 0);
    for (int iter = 0; iter < iterations; ++iter) {
        vector<float> gradients(featureCount, 0);
        float biasGradient = 0;
        for (size_t i = 0; i < features.size(); ++i) {
            float prediction = bias;
            for (size_t j = 0; j < featureCount; ++j) {
                prediction += features[i][j] * weights[j];
            }
            float error = prediction - labels[i];
            biasGradient += error;
            for (size_t j = 0; j < featureCount; ++j) {
                gradients[j] += error * features[i][j];
            }
        }
        bias -= learningRate * biasGradient / features.size();
        for (size_t j = 0; j < featureCount; ++j) {
            weights[j] -= learningRate * gradients[j] / features.size();
        }
    }
}