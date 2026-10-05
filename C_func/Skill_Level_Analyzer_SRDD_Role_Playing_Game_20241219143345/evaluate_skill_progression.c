int evaluate_skill_progression(int progression) {
    if (progression <= 0) return 10;
    if (progression > 100) return 1;
    return 100 / progression; 
}