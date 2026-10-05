void Dungeon::generateDungeon(int level) {
    puzzles.clear();
    for (int i = 0; i < level + 2; i++) {
        Puzzle puzzle;
        puzzles.push_back(puzzle);
    }
}