double AudioProcessor::compareAudio() {
    cout << "Comparing audio..." << endl;
    return calculateSimilarity(recordedAudio, nativeAudio);
}