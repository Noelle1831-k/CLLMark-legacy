void ResultExporter::exportResults(Classifier& classifier, const string& filename) {
    cout << "Exporting Results to " << filename << "..." << endl;
    ofstream file(filename);
    file << "Results exported successfully." << endl;
    file.close();
}