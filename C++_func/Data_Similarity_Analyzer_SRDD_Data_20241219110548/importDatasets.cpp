void UserInterface::importDatasets() {
    int numDatasets;
    cout << "Enter the number of datasets to import: ";
    cin >> numDatasets;
    for (int i = 0; i < numDatasets; ++i) {
        string filename;
        cout << "Enter the filename for dataset " << i + 1 << ": ";
        cin >> filename;
        Dataset dataset;
        dataset.loadData(filename);
        datasets.push_back(dataset);
    }
}