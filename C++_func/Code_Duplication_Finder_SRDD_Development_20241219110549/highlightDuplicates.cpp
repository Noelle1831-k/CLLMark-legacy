void DuplicateHighlighter::highlightDuplicates(const vector<string>& duplicates) {
    for (size_t i = 0; i < duplicates.size(); ++i) {
        cout << "Duplicate Code: " << duplicates[i] << endl;
    }
}