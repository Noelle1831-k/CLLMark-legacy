bool FileManager::validateFile(const string& filePath) {
    ifstream file(filePath.c_str());
    return file.good();
}