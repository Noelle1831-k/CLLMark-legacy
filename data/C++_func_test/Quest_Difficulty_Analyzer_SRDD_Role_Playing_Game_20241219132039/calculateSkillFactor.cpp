double DifficultyCalculator::calculateSkillFactor(int requiredSkills) {
    if (requiredSkills < 1) requiredSkills = 1; 
    return log(1 + requiredSkills) * 12;
}