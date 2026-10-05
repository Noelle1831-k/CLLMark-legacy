int main() {
    char root[3];
    char scaleType[20];
    char scaleNotes[MAX_SCALE_NOTES];
    handleUserInput(root, scaleType);
    generateScale(root, scaleType, scaleNotes);
    displayResults(scaleNotes);
    playScale(scaleNotes);
    displayKeyboard(scaleNotes);
    displayStaff(scaleNotes);
    return 0;
}