int main() {
    Kingdom myKingdom;
    Diplomacy diplomacy;
    Warfare warfare;
    ResourceManager resourceManager;
    int choice;
    string structureType;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter structure type to build (Castle/Farm/Market): ";
                cin >> structureType;
                myKingdom.buildStructure(structureType);
                break;
            case 2:
                cout << "Enter structure type to upgrade (Castle/Farm/Market): ";
                cin >> structureType;
                myKingdom.upgradeStructure(structureType);
                break;
            case 3:
                myKingdom.manageResources();
                break;
            case 4:
                myKingdom.displayStatus();
                break;
            case 5:
                diplomacy.negotiate();
                break;
            case 6:
                warfare.planAttack();
                break;
            case 7:
                warfare.defend();
                break;
            case 8:
                resourceManager.allocateResources();
                break;
            case 9:
                resourceManager.gatherResources();
                break;
            case 0:
                cout << "Exiting game. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}