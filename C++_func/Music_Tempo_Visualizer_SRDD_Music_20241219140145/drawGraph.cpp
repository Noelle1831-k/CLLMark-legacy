void Visualizer::drawGraph(const vector<float>& tempoData) {
    cout << "Visualizing Tempo Data:" << endl;
    for (size_t i = 0; i < tempoData.size(); ++i) {
        int numStars = static_cast<int>(tempoData[i]);
        cout << "Time " << i << ": " << string(numStars, '*') << " Tempo: " << tempoData[i] << " BPM" << endl;
    }
}