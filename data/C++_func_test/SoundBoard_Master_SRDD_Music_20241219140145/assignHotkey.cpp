void SoundBoard::assignHotkey(const string& filePath, char hotkey) {
    hotkeyMap[hotkey] = filePath;
    cout << "Assigned hotkey " << hotkey << " to sound clip: " << filePath << endl;
}