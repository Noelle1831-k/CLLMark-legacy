void Schedule::generateSchedule(Event &event, Team &teamManager, Referee &refereeManager) {
    vector<string> teams = teamManager.getTeams();
    vector<string> referees = refereeManager.getReferees();
    for (int i = 0; i < teams.size(); i += 2) {
        if (i + 1 < teams.size()) {
            string match = teams[i] + " vs " + teams[i + 1] + " (Referee: " + referees[i % referees.size()] + ")";
            matches.push_back(match);
        }
    }
}