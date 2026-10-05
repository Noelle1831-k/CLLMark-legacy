bool FileHandler::loadFile(const string& filePath) {
    essentia::init();
    AlgorithmFactory& factory = AlgorithmFactory::instance();
    Algorithm* loader = factory.create("MonoLoader");
    loader->set("filename", filePath);
    vector<Real> audioDataVector;
    loader->compute("audio", audioDataVector);
    if (audioDataVector.empty()) {
        cerr << "Error processing file: " << filePath << endl;
        return false;
    }
    audioData = audioDataVector;
    return true;
}