void HealthTracker::viewFamilyMemberProfile(const std::string& name) const {
    for (size_t i = 0; i < familyMembers.size(); i++) {
        if (familyMembers[i].getName() == name) {
            familyMembers[i].displayProfile();
            return;
        }
    }
    std::cout << "No family member found with the name: " << name << "\n";
}