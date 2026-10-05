int main() {
    Leaderboard leaderboard;
    User* users[10];  
    Chore* chores[10];  
    RewardSystem reward_system = {0};  
    initialize_system(&leaderboard, users, chores, &reward_system);
    run_application(&leaderboard, users, chores, &reward_system);
    return 0;
}