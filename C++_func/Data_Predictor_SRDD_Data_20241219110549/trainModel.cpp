void ModelTrainer::trainModel(const vector<vector<double>>& data, const vector<double>& target) {
    size_t numFeatures = data[0].size();
    coefficients.resize(numFeatures + 1, 0.0); 
    cout << "Training model..." << endl;
    double learningRate = 0.01;
    int iterations = 1000;
    for (int iter = 0; iter < iterations; ++iter) {
        vector<double> gradients(numFeatures + 1, 0.0);
        for (size_t i = 0; i < data.size(); ++i) {
            double prediction = coefficients[0]; 
            for (size_t j = 0; j < numFeatures; ++j) {
                prediction += coefficients[j + 1] * data[i][j];
            }
            double error = prediction - target[i];
            gradients[0] += error;
            for (size_t j = 0; j < numFeatures; ++j) {
                gradients[j + 1] += error * data[i][j];
            }
        }
        for (size_t j = 0; j < coefficients.size(); ++j) {
            coefficients[j] -= learningRate * gradients[j] / data.size();
        }
    }
}