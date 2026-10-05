void RhythmPattern::generatePattern(int difficulty) {
    pattern.clear();
    for (int i = 0; i < difficulty * 4; ++i) {
        pattern.push_back(rand() % 2); 
    }
}