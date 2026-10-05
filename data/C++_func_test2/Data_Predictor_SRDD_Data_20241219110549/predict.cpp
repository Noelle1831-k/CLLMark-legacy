double Predictor::predict(const vector<double>& instance) {
    cout << "Predicting..." << endl;
    double prediction = coefficients[0]; 
    for (size_t i = 0; i < instance.size(); ++i) {
        prediction += coefficients[i + 1] * instance[i];
    }
    return prediction;
}