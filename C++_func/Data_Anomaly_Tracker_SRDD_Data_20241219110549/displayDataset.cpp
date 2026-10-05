void DatasetManager::displayDataset() {
    cout << "Dataset Headers: " << endl;
    for (const auto &header : headers) {
        cout << header << " ";
    }
    cout << endl;
    cout << "Total Rows: " << dataset.size() << endl;
}