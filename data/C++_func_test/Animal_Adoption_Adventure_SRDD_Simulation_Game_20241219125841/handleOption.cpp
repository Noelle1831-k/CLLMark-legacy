void Game::handleOption(int option) {
    switch (option) {
        case 1: {
            string name, species, healthStatus;
            int age;
            cout << "Enter animal details (Name, Species, Age, Health Status): ";
            cin >> name >> species >> age >> healthStatus;
            Animal newAnimal(name, species, age, healthStatus);
            adoptionCenter.rescueAnimal(newAnimal);
            break;
        }
        case 2:
            adoptionCenter.provideMedicalCare();
            break;
        case 3:
            adoptionCenter.findHome();
            break;
        case 4: {
            string eventName;
            cout << "Enter the name of the fundraising event: ";
            cin.ignore();
            getline(cin, eventName);
            fundraising.organizeEvent(eventName);
            fundraising.collectDonations(500.0); 
            break;
        }
        case 5: {
            string programName;
            cout << "Enter the name of the community outreach program: ";
            cin.ignore();
            getline(cin, programName);
            communityOutreach.launchProgram(programName);
            communityOutreach.engageCommunity();
            break;
        }
        case 6:
            for (int i = 0; i < volunteers.size(); i++) {
                volunteers[i].assist();
                volunteers[i].reportHours();
            }
            break;
        case 7:
            endGame();
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
    }
}