int main() {
    int choice;
    Metronome metronome;
    RhythmExercise exercise;
    Feedback feedback;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Starting a new rhythm exercise..." << endl;
                exercise.startExercise();
                break;
            case 2:
                int tempo;
                cout << "Enter new tempo: ";
                cin >> tempo;
                metronome.setTempo(tempo);
                cout << "Metronome tempo updated!" << endl;
                break;
            case 3:
                cout << "Generating progress report..." << endl;
                feedback.generateReport();
                break;
            case 4:
                cout << "Starting metronome..." << endl;
                metronome.startMetronome();
                break;
            case 5:
                cout << "Stopping metronome..." << endl;
                metronome.stopMetronome();
                break;
            case 6:
                cout << "Exiting program. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    }
    return 0;
}