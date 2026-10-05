int main() {
    int choice;
    cout << "Welcome to GardenTime!" << endl;
    cout << "Learn about gardening, plants, and sustainability." << endl;
    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Plant Identification" << endl;
        cout << "2. Gardening Tutorials" << endl;
        cout << "3. Take a Quiz" << endl;
        cout << "4. Environmental Sustainability" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Plant plant;
                plant.identifyPlant();
                break;
            }
            case 2: {
                Tutorial tutorial;
                tutorial.displayTutorial();
                break;
            }
            case 3: {
                Quiz quiz;
                quiz.startQuiz();
                break;
            }
            case 4: {
                Sustainability sustainability;
                sustainability.getTips();
                break;
            }
            case 5:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);
    return 0;
}