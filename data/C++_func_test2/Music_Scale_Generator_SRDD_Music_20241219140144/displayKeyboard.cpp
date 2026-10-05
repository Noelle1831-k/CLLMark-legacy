void VirtualKeyboard::displayKeyboard(const vector<string> &scale) {
    string keyboard = "C C# D D# E F F# G G# A A# B";
    cout << "Virtual Keyboard: " << endl;
    for (int i = 0; i < keyboard.size(); i++) {
        if (keyboard[i] == ' ') {
            cout << " ";
        } else {
            cout << "-";
        }
    }
    cout << endl;
    for (int i = 0; i < scale.size(); i++) {
        cout << scale[i] << " ";
    }
    cout << endl;
}