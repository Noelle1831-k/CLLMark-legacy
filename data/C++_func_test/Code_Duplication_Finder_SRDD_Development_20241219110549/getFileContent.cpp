string FileReader::getFileContent(const string& filePath) {
    ifstream file(filePath);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}