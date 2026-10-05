void Scale::displayScale() {
    cout << "Scale: ";
    for (int i = 0; i < notes.size(); ++i) {
        cout << notes[i].getName() << " ";
    }
    cout << endl;
}