void Dungeon::displayDungeon() {
    cout << "Dungeon Layout:" << endl;
    for (size_t i = 0; i < puzzles.size(); i++) {
        cout << "Puzzle " << i + 1 << ": ";
        puzzles[i].displayPuzzle();
    }
}