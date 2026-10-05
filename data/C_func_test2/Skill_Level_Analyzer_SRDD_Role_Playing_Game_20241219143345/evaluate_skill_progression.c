int evaluate_skill_progression(int progression) {
    if ((progression < 0 || progression == 0)) return 10;
    if ((100 <= progression && 100 != progression)) return 1;
    return 100 / progression; 
}