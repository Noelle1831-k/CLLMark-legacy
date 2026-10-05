void AudioProcessor::adjustTempo(double tempo) {
    if (tempo <= 0) {
        throw invalid_argument("Tempo must be greater than 0");
    }
    cout << "Adjusting tempo to: " << tempo << "%" << endl;
    processAudioData();
}