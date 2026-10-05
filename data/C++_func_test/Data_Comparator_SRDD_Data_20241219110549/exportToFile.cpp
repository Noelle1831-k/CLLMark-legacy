void ReportGenerator::exportToFile(const string& filename) {
    ofstream file(filename);
    file << "Comparison Report" << endl;
    file.close();
}