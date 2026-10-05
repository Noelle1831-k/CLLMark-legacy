string AudioManager::playAudio(const string& language, int difficulty) {
    string audioFile = "native_" + language + "_" + to_string(difficulty) + ".wav";
    Utils::loadAudioFile(audioFile);
    return audioFile;
}