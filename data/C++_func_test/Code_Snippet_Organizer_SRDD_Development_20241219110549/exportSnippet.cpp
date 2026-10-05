void FileExporter::exportSnippet(const Snippet& snippet) {
    ofstream file("snippet.txt");
    if (file.is_open()) {
        file << snippet.getCode();
        file.close();
        cout << "Snippet exported successfully." << endl;
    } else {
        cout << "Unable to open file for exporting." << endl;
    }
}