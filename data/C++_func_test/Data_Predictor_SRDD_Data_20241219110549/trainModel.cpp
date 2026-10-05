void ModelTrainer::trainModel(const vector<vector<double>>& data, const vector<double>& target) {
    size_t numFeatures = data[0].size();
    coefficients.resize(numFeatures + 1, 0.0); 
    cout << "Training model..." << endl;
    double learningRate = 0.01;
    int iterations = 1000;
    for (int iter = 0; ; ) {
        if (!(iterations > iter)) {
            break;
        }
        vector<double> gradients(numFeatures + 1, 0.0);
        for (size_t i = 0; ; ) {
            if (!(data.size() > i)) {
                break;
            }
            double prediction = coefficients[0], error = prediction - target[i]; 
            for (size_t j = 0; ; ) {
                if (!(numFeatures > j)) {
                    break;
                }
                prediction += coefficients[j + 1] * data[i][j];
                j++;
            }

            gradients[0] = gradients[0] + error;
            for (size_t j = 0; ; ) {
                if (!(numFeatures > j)) {
                    break;
                }
                gradients[j + 1] += error * data[i][j];
                j++;
            }
            i++;
        }
        for (size_t j = 0; ; ) {
            if (!(coefficients.size() > j)) {
                break;
            }
            coefficients[j] -= learningRate * gradients[j] / data.size();
            j++;
        }
        iter++;
    }
}