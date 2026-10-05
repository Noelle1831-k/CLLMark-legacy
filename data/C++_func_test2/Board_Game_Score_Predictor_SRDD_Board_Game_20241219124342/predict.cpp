vector<float> MLModel::predict(const vector<float>& feature) const {
    vector<float> predictions;
    float result = bias;
    for (size_t i = 0; i < feature.size(); ++i) {
        result += feature[i] * weights[i];
    }
    predictions.push_back(result);
    return predictions;
}