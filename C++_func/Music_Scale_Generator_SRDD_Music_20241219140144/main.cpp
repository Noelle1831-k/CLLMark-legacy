int main() {
    cout << "Welcome to the Music Scale Generator!" << endl;
    string rootNote;
    string scaleType;
    int transposeSteps;
    while (true) {
        cout << "Enter the root note (e.g., C, D#, F): ";
        cin >> rootNote;
        if (rootNote == "C" || rootNote == "C#" || rootNote == "D" || rootNote == "D#" || 
            rootNote == "E" || rootNote == "F" || rootNote == "F#" || rootNote == "G" || 
            rootNote == "G#" || rootNote == "A" || rootNote == "A#" || rootNote == "B") {
            break;
        } else {
            cout << "Invalid root note. Please try again." << endl;
        }
    }
    while (true) {
        cout << "Enter the scale type (e.g., major, minor, pentatonic): ";
        cin >> scaleType;
        if (scaleType == "major" || scaleType == "minor" || scaleType == "pentatonic") {
            break;
        } else {
            cout << "Invalid scale type. Please try again." << endl;
        }
    }
    ScaleGenerator scaleGen;
    vector<string> scale = scaleGen.generateScale(rootNote, scaleType);
    cout << "Generated Scale: ";
    for (int i = 0; i < scale.size(); i++) {
        cout << scale[i] << " ";
    }
    cout << endl;
    VirtualKeyboard keyboard;
    keyboard.displayKeyboard(scale);
    MusicStaff staff;
    staff.displayStaff(scale);
    AudioPlayer player;
    player.playScale(scale);
    while (true) {
        cout << "Enter the number of semitones to transpose the scale (-12 to +12): ";
        cin >> transposeSteps;
        if (transposeSteps >= -12 && transposeSteps <= 12) {
            break;
        } else {
            cout << "Invalid input. Please enter a value between -12 and +12." << endl;
        }
    }
    vector<string> transposedScale = scaleGen.transposeScale(scale, transposeSteps);
    cout << "Transposed Scale: ";
    for (int i = 0; i < transposedScale.size(); i++) {
        cout << transposedScale[i] << " ";
    }
    cout << endl;
    keyboard.displayKeyboard(transposedScale);
    staff.displayStaff(transposedScale);
    player.playScale(transposedScale);
    cout << "Thank you for using the Music Scale Generator!" << endl;
    return 0;
}