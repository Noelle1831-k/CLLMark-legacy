int main() {
    cout << "Welcome to the Data Classifier Application!" << endl;
    DataImporter importer;
    vector<vector<double>> data = importer.importData("dataset.csv");
    DataPreprocessor preprocessor;
    vector<vector<double>> processedData = preprocessor.preprocess(data);
    DecisionTreeClassifier classifier;
    classifier.train(processedData);
    ModelEvaluator evaluator;
    double accuracy = evaluator.evaluate(classifier, processedData);
    cout << "Model Accuracy: " << accuracy << "%" << endl;
    ResultExporter exporter;
    exporter.exportResults(classifier, "results.csv");
    cout << "Process completed successfully!" << endl;
    return 0;
}