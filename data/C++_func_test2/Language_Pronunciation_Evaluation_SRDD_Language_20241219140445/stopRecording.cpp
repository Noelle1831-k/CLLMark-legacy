void AudioRecorder::stopRecording() {
    if (stream && isRecording) {
        Pa_StopStream(stream);
        isRecording = false;
    }
}