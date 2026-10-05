void SkillTree::addSkill(Skill* skill, SkillNode* parentNode) {
    SkillNode* newNode = new SkillNode(skill);
    parentNode->addChildNode(newNode);
}