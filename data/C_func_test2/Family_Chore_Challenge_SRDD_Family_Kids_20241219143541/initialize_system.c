void initialize_system(Leaderboard* leaderboard, User* users[], Chore* chores[], RewardSystem* reward_system) {
    users[0] = (User*)malloc(sizeof(User));
    strcpy(users[0]->name, "Alice");
    users[0]->points = 0;
    users[0]->id = 1;
    strcpy(users[0]->role, "parent");
    users[1] = (User*)malloc(sizeof(User));
    strcpy(users[1]->name, "Bob");
    users[1]->points = 0;
    users[1]->id = 2;
    strcpy(users[1]->role, "child");
    leaderboard->users[0] = users[0];
    leaderboard->users[1] = users[1];
    leaderboard->user_count = 2;
    chores[0] = (Chore*)malloc(sizeof(Chore));
    strcpy(chores[0]->description, "Clean the dishes");
    chores[0]->points = 10;
    strcpy(chores[0]->deadline, "2024-12-20");
    chores[0]->assigned_user = users[0]; 
    chores[1] = (Chore*)malloc(sizeof(Chore));
    strcpy(chores[1]->description, "Take out the trash");
    chores[1]->points = 5;
    strcpy(chores[1]->deadline, "2024-12-19");
    chores[1]->assigned_user = users[1]; 
}