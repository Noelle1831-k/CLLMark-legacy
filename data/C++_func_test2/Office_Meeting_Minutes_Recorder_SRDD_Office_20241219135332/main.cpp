int main() {
    UserInterface ui;
    MeetingRecorder recorder;
    AudioRecorder audio;
    NotesManager notes;
    MeetingOrganizer organizer;
    ui.displayWelcomeMessage();
    while (true) {
        int choice = ui.getUserChoice();
        switch (choice) {
            case 1:
                recorder.recordMeetingDetails();
                break;
            case 2:
                audio.startRecording();
                break;
            case 3:
                notes.addNote();
                break;
            case 4:
                organizer.organizeMeetings();
                break;
            case 5:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}