void AudioRecorder::startRecording() {
    if (!isRecording) {
        isRecording = true;
        cout << "Audio recording started." << endl;
    } else {
        cout << "Recording is already in progress." << endl;
    }
}