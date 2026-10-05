void SkillNode::addChildNode(SkillNode* child) {
    childNodes.push_back(child);
    child->parentNode = this;
}