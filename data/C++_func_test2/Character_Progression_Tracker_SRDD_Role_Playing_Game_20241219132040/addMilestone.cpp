void ProgressionTracker::addMilestone(int level, Character character) {
    milestones[level] = character;
    std::cout << "Milestone added at level " << level << "." << std::endl;
}