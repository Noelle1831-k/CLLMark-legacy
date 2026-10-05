void assignChores(Child& child) {
        for (auto& chore : chores) {
            bool onTime;
            cout << "Did " << child.name << " complete the chore '" << chore->name << "' on time? (1 for yes, 0 for no): ";
            cin >> onTime;
            child.completeChore(chore, onTime);
        }
    }