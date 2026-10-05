int main() {
    UIManager uiManager;
    AudioMixer mixer;
    AudioEffects effects;
    bool running = true;
    while (running) {
        uiManager.displayMenu();
        int choice = uiManager.getUserInput();
        switch (choice) {
            case 1: {
                string fileName;
                cout << "Enter audio file name to load: ";
                cin >> fileName;
                AudioFile audioFile(fileName);
                audioFile.loadFile();
                mixer.addTrack(audioFile);
                break;
            }
            case 2: {
                int trackIndex;
                float volume;
                cout << "Enter track index to adjust volume: ";
                cin >> trackIndex;
                cout << "Enter new volume level (0.0 to 1.0): ";
                cin >> volume;
                mixer.adjustVolume(trackIndex, volume);
                break;
            }
            case 3: {
                int track1, track2;
                cout << "Enter indices of two tracks to crossfade: ";
                cin >> track1 >> track2;
                mixer.applyCrossfade(track1, track2);
                break;
            }
            case 4: {
                mixer.synchronizeBeats();
                break;
            }
            case 5: {
                int trackIndex;
                float tempo;
                cout << "Enter track index to adjust tempo: ";
                cin >> trackIndex;
                cout << "Enter new tempo multiplier: ";
                cin >> tempo;
                effects.adjustTempo(trackIndex, tempo);
                break;
            }
            case 6: {
                int trackIndex;
                float pitchShift;
                cout << "Enter track index to shift pitch: ";
                cin >> trackIndex;
                cout << "Enter pitch shift value: ";
                cin >> pitchShift;
                effects.shiftPitch(trackIndex, pitchShift);
                break;
            }
            case 0: {
                running = false;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        uiManager.updateUI();
    }
    cout << "Exiting Music Blendr. Goodbye!" << endl;
    return 0;
}