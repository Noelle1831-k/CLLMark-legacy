void FrequencyAnalyzer::generateFrequencyTable(const map<int, int>& frequencyTable) {
    cout << "Frequency Table:" << endl;
    cout << setw(10) << "Value" << setw(10) << "Frequency" << endl;
    for (map<int, int>::const_iterator it = frequencyTable.begin(); it != frequencyTable.end(); ++it) {
        cout << setw(10) << it->first << setw(10) << it->second << endl;
    }
}