int main() {
    UserInterface ui;
    AudioProcessor ap;
    FileHandler fh;
    string filePath = "input_audio.wav";
    string outputFilePath = "output_audio.wav";
    try {
        fh.readFile(filePath);
        double desiredTempo = ui.getUserInput();
        ap.loadAudioFile(filePath);
        ap.adjustTempo(desiredTempo);
        ap.maintainPitch();
        fh.writeFile(outputFilePath);
        ui.displayResult(outputFilePath);
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}