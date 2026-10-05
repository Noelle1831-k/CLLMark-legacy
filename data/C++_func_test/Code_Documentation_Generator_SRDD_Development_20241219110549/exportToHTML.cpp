void HTMLExporter::exportToHTML(const string& documentation, const string& filePath) {
    ofstream file(filePath.c_str());
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filePath << endl;
        return;
    }
    file << documentation;
    file.close();
}