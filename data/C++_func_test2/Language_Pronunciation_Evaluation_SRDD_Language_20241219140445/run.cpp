void run() {
        UserInterface ui;
        AudioRecorder recorder;
        PronunciationAnalyzer analyzer;
        ui.displayInstructions();
        if (!recorder.initialize()) {
            cerr << "Error: Failed to initialize audio recorder." << endl;
            return;
        }
        recorder.startRecording();
        cout << "Recording in progress... Please speak now." << endl;
        for (long i = 0; i < 500000000; ++i);
        recorder.stopRecording();
        vector<float> audioData = recorder.getAudioData();
        if (audioData.empty()) {
            cerr << "Error: No audio data captured." << endl;
            return;
        }
        double score = analyzer.analyzePronunciation(audioData);
        string feedback = analyzer.provideFeedback(score);
        ui.displayFeedback(feedback);
        recorder.terminate();
    }