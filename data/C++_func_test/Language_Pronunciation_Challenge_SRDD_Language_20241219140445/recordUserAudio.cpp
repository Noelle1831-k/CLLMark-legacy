string AudioManager::recordUserAudio() {
    string userAudioFile = "user_audio.wav";
    Utils::saveAudioFile(userAudioFile);
    return userAudioFile;
}