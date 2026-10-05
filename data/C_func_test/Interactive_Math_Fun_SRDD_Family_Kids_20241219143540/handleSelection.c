void handleSelection(int choice) {
    switch (choice) {
        case 1:
            generateAdditionProblem();
            break;
        case 2:
            generateSubtractionProblem();
            break;
        case 3:
            generateMultiplicationProblem();
            break;
        case 4:
            generateDivisionProblem();
            break;
        case 5:
            displayScore();
            break;
        case 6:
            displayLeaderboard();
            break;
        case 7:
            displayMessage("Thank you for playing! Goodbye!\n");
            exit(0);
        default:
            displayMessage("Invalid choice. Please try again.\n");
    }
}