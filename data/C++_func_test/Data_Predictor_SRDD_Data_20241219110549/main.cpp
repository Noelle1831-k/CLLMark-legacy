int main() {
    DataImporter importer;
    DataPreprocessor preprocessor;
    ModelTrainer trainer;
    Predictor predictor;
    string filePath = "data.csv";
    vector<vector<double>> data;
    vector<double> target;
    data = importer.importData(filePath);
    preprocessor.preprocessData(data);
    for (size_t i = 0; i < data.size(); ++i) {
        target.push_back(data[i].back());
        data[i].pop_back();
    }
    trainer.trainModel(data, target);
    vector<double> newInstance = {5.1, 3.5, 1.4, 0.2}; 
    double prediction = predictor.predict(newInstance);
    cout << "Prediction: " << prediction << endl;
    return 0;
}