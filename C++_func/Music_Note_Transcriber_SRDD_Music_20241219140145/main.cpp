int main() {
    UserInterface ui;
    AudioInputHandler audioHandler;
    AudioProcessor audioProcessor;
    NoteRecognizer noteRecognizer;
    ui.displayWelcomeMessage();
    string userChoice = ui.getUserInput();
    if (userChoice == "1") {
        cout << "Recording audio..." << endl;
        if (!audioHandler.recordAudio()) {
            cerr << "Error: Failed to record audio." << endl;
            return -1;
        }
        string filename = "recorded_audio.wav";
        if (!audioHandler.saveAudioToFile(filename)) {
            cerr << "Error: Failed to save recorded audio." << endl;
            return -1;
        }
        cout << "Processing audio..." << endl;
        if (!audioProcessor.loadAudioFile(filename)) {
            cerr << "Error: Failed to load audio file for processing." << endl;
            return -1;
        }
        vector<double> frequencyData = audioProcessor.extractFrequencyData();
        vector<double> transformedData = audioProcessor.applyFourierTransform(frequencyData);
        cout << "Recognizing notes..." << endl;
        vector<string> notes = noteRecognizer.mapFrequencyToNotes(transformedData);
        string noteSequence = noteRecognizer.generateNoteSequence(notes);
        ui.displayTranscribedNotes(noteSequence);
    } else {
        cout << "Exiting application. Goodbye!" << endl;
    }
    return 0;
}