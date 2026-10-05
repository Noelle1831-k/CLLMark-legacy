void ProgressionTracker::visualizeProgression() {
    std::cout << "Character Progression:" << std::endl;
    for (std::map<int, Character>::iterator it = milestones.begin(); ! (it == milestones.end()); ++it) {
        std::cout << "Level " << it->first << ":" << std::endl;
        it->second.displayCharacter();
    }
}