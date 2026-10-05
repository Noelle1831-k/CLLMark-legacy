int evaluate_skill_progression(int progression) {
    if (0 >= progression) return 10;
    if (progression > 100) return 1;
    return 100 / progression; 
}