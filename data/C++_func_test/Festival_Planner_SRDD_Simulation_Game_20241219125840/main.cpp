int main(int argc, char *argv[]) {
    srand(time(0)); 
    cout << "Welcome to Festival Planner!" << endl;
    FestivalManager festivalManager;
    festivalManager.initializeFestival();
    char continueSimulation = 'y';
    while (continueSimulation == 'y' || continueSimulation == 'Y') {
        festivalManager.simulateDay();
        cout << "Do you want to continue to the next day? (y/n): ";
        cin >> continueSimulation;
    }
    festivalManager.generateReport();
    cout << "Thank you for playing Festival Planner!" << endl;
    return 0;
}