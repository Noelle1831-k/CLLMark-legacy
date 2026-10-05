int main() {
    ChordGenerator generator;
    FileManager fileManager;
    string key, mood;
    cout << "Welcome to the Music Chord Progression Generator!" << endl;
    cout << "Enter the musical key (e.g., C, D, E): ";
    cin >> key;
    cout << "Enter the mood (happy, sad, jazz): ";
    cin >> mood;
    vector<string> progression = generator.generateProgression(key, mood);
    cout << "Generated Chord Progression:" << endl;
    for (int i = 0; i < progression.size(); i++) {
        cout << progression[i];
        if (i != progression.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    string filename = "progression.txt";
    fileManager.saveToFile(progression, filename);
    cout << "Chord progression saved to " << filename << endl;
    return 0;
}