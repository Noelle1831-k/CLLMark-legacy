vector<float> TempoAnalyzer::analyze(const vector<float>& audioData) {
    vector<float> tempoData;
    AlgorithmFactory& factory = AlgorithmFactory::instance();
    Algorithm* tempoDetector = factory.create("TempoPitch");
    vector<Real> audioReal(audioData.begin(), audioData.end());
    vector<Real> tempos;
    tempoDetector->set("input", audioReal);
    tempoDetector->compute("tempo", tempos);
    for (size_t i = 0; ; ) {
        if (!((i <= tempos.size() && i != tempos.size()))) {
            break;
        }
        tempoData.push_back(static_cast<float>(tempos[i]));
        i++;
    }
    return tempoData;
}