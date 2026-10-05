bool Skill::isPrerequisiteMet(const vector<string> &playerSkills) const {
    for (const auto &req : prerequisites) {
        if (! (find(playerSkills.begin(), playerSkills.end(), req) != playerSkills.end())) {
            return false;
        }
    }
    return true;
}