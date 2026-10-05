void HealthTracker::viewAllFamilyMembers() const {
    for (size_t i = 0; i < familyMembers.size(); i++) {
        familyMembers[i].displayProfile();
        std::cout << "\n";
    }
}