void AudioProcessor::processAudio() {
    cout << "Processing audio..." << endl;
    extractFrequencies();
    performFFTAnalysis();
}