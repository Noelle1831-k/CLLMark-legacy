void DataValidator::validateData() {
    cout << "Starting data validation process..." << endl;
    qualityChecks.checkMissingValues(dataset);
    qualityChecks.checkDataTypes(dataset);
    qualityChecks.checkDuplicates(dataset);
}