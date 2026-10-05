bool Player::canLearnSkill(const Skill& skill) {
    return (strength + intelligence + dexterity >= skill.getSkillDetails().requiredAttributes && 
            availableResources >= 10);
}