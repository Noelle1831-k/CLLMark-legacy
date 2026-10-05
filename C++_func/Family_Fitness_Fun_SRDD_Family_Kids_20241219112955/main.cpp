int main() {
    srand(time(0));  
    User user1("Alice", 25);
    User user2("Bob", 30);
    User user3("Charlie", 5);
    Family family1("Smith Family");
    family1.addMember(user1);
    family1.addMember(user2);
    family1.addMember(user3);
    FitnessChallenge challenge1("10-minute Jumping Jacks Challenge", 10);
    FitnessChallenge challenge2("Family Yoga Session", 30);
    VideoTutorial tutorial1("Basic Yoga Techniques");
    VideoTutorial tutorial2("How to Stay Motivated for Fitness");
    int choice;
    bool exitApp = false;
    while (!exitApp) {
        cout << "Welcome to FamilyFitnessFun!" << endl;
        cout << "1. View Family Progress" << endl;
        cout << "2. View Fitness Challenges" << endl;
        cout << "3. View Video Tutorials" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                family1.viewFamilyProgress();
                break;
            case 2:
                challenge1.showChallenge();
                challenge2.showChallenge();
                family1.completeChallenge(challenge1);
                family1.completeChallenge(challenge2);
                break;
            case 3:
                tutorial1.showTutorial();
                tutorial2.showTutorial();
                break;
            case 4:
                exitApp = true;
                cout << "Exiting FamilyFitnessFun. Stay healthy!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}