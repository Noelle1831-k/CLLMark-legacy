int analyze_skill_difficulty(Skill skill) {
    int attribute_score = calculate_attribute_score(skill.required_attributes);
    int complexity_factor = calculate_complexity_factor(skill.complexity);
    int progression_factor = evaluate_skill_progression(skill.progression);
    int difficulty = (attribute_score * 2 + complexity_factor * 3 + progression_factor * 5) / 10;
    return difficulty;
}