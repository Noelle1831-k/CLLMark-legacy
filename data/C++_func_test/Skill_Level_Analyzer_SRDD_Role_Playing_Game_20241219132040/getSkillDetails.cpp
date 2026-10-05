string Skill::getSkillDetails() {
    return "Skill: " + name + "\nAttributes: " + to_string(requiredAttributes) + 
           "\nComplexity: " + to_string(complexity) +
           "\nProgression: " + to_string(progression) +
           "\nDifficulty Rating: " + to_string(difficultyRating);
}