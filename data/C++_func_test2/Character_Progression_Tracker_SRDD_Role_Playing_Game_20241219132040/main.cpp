int main() {
    Character character;
    ProgressionTracker tracker;
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        if (choice == 1) {
            std::string attrName;
            int attrValue;
            std::cout << "Enter attribute name: ";
            std::cin >> attrName;
            std::cout << "Enter attribute value: ";
            std::cin >> attrValue;
            character.addAttribute(attrName, attrValue);
        } else if (choice == 2) {
            std::string skillName;
            int skillLevel;
            std::cout << "Enter skill name: ";
            std::cin >> skillName;
            std::cout << "Enter skill level: ";
            std::cin >> skillLevel;
            character.addSkill(skillName, skillLevel);
        } else if (choice == 3) {
            std::string equipName, equipType;
            std::cout << "Enter equipment name: ";
            std::cin >> equipName;
            std::cout << "Enter equipment type: ";
            std::cin >> equipType;
            character.addEquipment(equipName, equipType);
        } else if (choice == 4) {
            int level;
            std::cout << "Enter milestone level: ";
            std::cin >> level;
            tracker.addMilestone(level, character);
        } else if (choice == 5) {
            tracker.visualizeProgression();
        } else if (choice == 6) {
            std::cout << "Exiting application. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}