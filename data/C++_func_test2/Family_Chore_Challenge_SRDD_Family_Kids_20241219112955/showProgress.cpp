void showProgress() {
        cout << name << "'s Progress:" << endl;
        cout << "Total Points: " << points << endl;
        cout << "Completed Chores: " << completedChores.size() << endl;
        for (auto& chore : completedChores) {
            chore->printChore();
        }
    }