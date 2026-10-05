void SkillNode::displayNodeInfo(int depth) const {
    for (int i = 0; i < depth; i++) cout << "--";
    cout << ">";
    skill->displaySkillInfo();
    for (auto child : childNodes) {
        child->displayNodeInfo(depth + 1);
    }
}