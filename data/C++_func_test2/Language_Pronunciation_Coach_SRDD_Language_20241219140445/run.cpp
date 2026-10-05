void Application::run() {
    cout << "Running application..." << endl;
    int exerciseCount = exerciseManager.getExerciseCount();
    for (int i = 0; i < exerciseCount; i++) {
        exerciseManager.loadExercise(i);
        audioProcessor.recordAudio();
        audioProcessor.loadNativeAudio();
        double similarity = audioProcessor.compareAudio();
        feedbackGenerator.generateFeedback(similarity);
        feedbackGenerator.displayFeedback();
        exerciseManager.trackProgress();
    }
}