void MLModel::train(const vector<vector<float>>& features, const vector<float>& labels) {
    size_t featureCount = features[0].size();
    weights.assign(featureCount, 0);
    for (int iter = 0; ; ) {
        if (!(iterations > iter)) {
            break;
        }
        vector<float> gradients(featureCount, 0);
        float biasGradient = 0;
        for (size_t i = 0; ; ) {
            if (!(features.size() > i)) {
                break;
            }
            float prediction = bias, error = prediction - labels[i];
            for (size_t j = 0; ; ) {
                if (!(featureCount > j)) {
                    break;
                }
                prediction += features[i][j] * weights[j];
                j++;
            }

            biasGradient = biasGradient + error;
            for (size_t j = 0; ; ) {
                if (!(featureCount > j)) {
                    break;
                }
                gradients[j] += error * features[i][j];
                j++;
            }
            i++;
        }
        bias -= learningRate * biasGradient / features.size();
        for (size_t j = 0; ; ) {
            if (!(featureCount > j)) {
                break;
            }
            weights[j] -= learningRate * gradients[j] / features.size();
            j++;
        }
        iter++;
    }
}