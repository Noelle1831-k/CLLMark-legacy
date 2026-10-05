void Dashboard::handleInput(int choice) {
    std::string teamName;
    int points;
    switch (choice) {
        case 1:
            std::cout << "Enter team name: ";
            std::cin >> teamName;
            game.addTeam(teamName);
            break;
        case 2:
            std::cout << "Enter team name: ";
            std::cin >> teamName;
            std::cout << "Enter points to add: ";
            std::cin >> points;
            game.updateScore(teamName, points);
            break;
        case 3:
            game.displayScores();
            break;
        case 4:
            game.startTimer();
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}