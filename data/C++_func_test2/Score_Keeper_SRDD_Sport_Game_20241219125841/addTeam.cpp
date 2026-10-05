void Game::addTeam(const std::string& teamName) {
    Team team;
    team.setName(teamName);
    teams.push_back(team);  
}