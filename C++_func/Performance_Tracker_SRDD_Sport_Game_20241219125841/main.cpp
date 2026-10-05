int main() {
    vector<Athlete> athletes;
    Dashboard dashboard;
    ReportGenerator reportGen;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1: {
                string name;
                cout << "Enter athlete name: ";
                cin.ignore();
                getline(cin, name);
                athletes.push_back(Athlete(name));
                cout << "Athlete added successfully.\n";
                break;
            }
            case 2: {
                string name;
                cout << "Enter athlete name: ";
                cin.ignore();
                getline(cin, name);
                Athlete* athlete = findAthlete(athletes, name);
                if (athlete) {
                    athlete->updateMetrics();
                } else {
                    cout << "Athlete not found.\n";
                }
                break;
            }
            case 3: {
                dashboard.display(athletes);
                break;
            }
            case 4: {
                reportGen.generate(athletes);
                break;
            }
            case 5: {
                cout << "Sorting athletes by speed...\n";
                sort(athletes.begin(), athletes.end(), [](const Athlete& a, const Athlete& b) {
                    return a.getMetrics().getSpeed() > b.getMetrics().getSpeed();
                });
                cout << "Athletes sorted successfully.\n";
                break;
            }
            case 6: {
                float avgSpeed = 0, avgAgility = 0, avgAccuracy = 0;
                for (size_t i = 0; i < athletes.size(); i++) {
                    avgSpeed += athletes[i].getMetrics().getSpeed();
                    avgAgility += athletes[i].getMetrics().getAgility();
                    avgAccuracy += athletes[i].getMetrics().getAccuracy();
                }
                if (!athletes.empty()) {
                    avgSpeed /= athletes.size();
                    avgAgility /= athletes.size();
                    avgAccuracy /= athletes.size();
                }
                cout << "Average Metrics:\n";
                cout << "Speed: " << avgSpeed << "\n";
                cout << "Agility: " << avgAgility << "\n";
                cout << "Accuracy: " << avgAccuracy << "\n";
                break;
            }
            case 7: {
                cout << "Exiting application.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}