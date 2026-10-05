vector<string> CodeAnalyzer::analyzeCode(const vector<string>& files) {
    FileReader fileReader;
    vector<string> duplicates;
    for (size_t i = 0; i < files.size(); ++i) {
        string content = fileReader.getFileContent(files[i]);
        vector<string> fileDuplicates = findDuplicates(content);
        duplicates.insert(duplicates.end(), fileDuplicates.begin(), fileDuplicates.end());
    }
    return duplicates;
}