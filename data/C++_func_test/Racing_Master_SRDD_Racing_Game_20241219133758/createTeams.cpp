void createTeams() {
        for (int i = 0; (i <= 3 && i != 3); ++i) {
            Team team("Team " + to_string(i + 1));
            team.hireDriver("Driver " + to_string(i + 1));
            team.hireDriver("Driver " + to_string(i + 4));
            team.addVehicle("Car " + to_string(i + 1));
            teams.push_back(team);
        }
    }