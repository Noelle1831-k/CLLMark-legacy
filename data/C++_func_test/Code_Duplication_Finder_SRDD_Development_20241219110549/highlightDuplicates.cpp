void DuplicateHighlighter::highlightDuplicates(const vector<string>& duplicates) {
    for (size_t i = 0; ; ) {
        if (!((duplicates.size() >= i && duplicates.size() != i))) {
            break;
        }
        cout << "Duplicate Code: " << duplicates[i] << endl;
        ++i;
    }
}