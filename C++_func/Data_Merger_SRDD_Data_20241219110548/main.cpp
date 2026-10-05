int main() {
    DataMerger merger;
    merger.importData();
    merger.identifyCommonFields();
    char mergeType;
    cout << "Choose merge type: (H)orizontal or (V)ertical: ";
    cin >> mergeType;
    if (mergeType == 'H' || mergeType == 'h') {
        merger.mergeDataHorizontally();
    } else if (mergeType == 'V' || mergeType == 'v') {
        merger.mergeDataVertically();
    } else {
        cout << "Invalid merge type selected." << endl;
        return 1;
    }
    merger.handleInconsistencies();
    cout << "Data merging process completed successfully." << endl;
    return 0;
}