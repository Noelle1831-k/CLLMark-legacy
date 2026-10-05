int main() {
    NoteManager noteManager;
    SearchEngine searchEngine(noteManager);
    while (true) {
        displayMenu();
        handleUserInput(noteManager, searchEngine);
    }
    return 0;
}