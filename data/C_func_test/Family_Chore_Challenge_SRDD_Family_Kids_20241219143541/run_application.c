void run_application(Leaderboard* leaderboard, User* users[], Chore* chores[], RewardSystem* reward_system) {
    int choice;
    while (1) {
        printf("\n*** Family Chore Challenge ***\n");
        printf("1. Display Leaderboard\n");
        printf("2. Complete a Chore\n");
        printf("3. Check Achievements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                update_leaderboard(leaderboard);
                display_leaderboard(leaderboard);
                break;
            case 2: {
                int chore_id;
                int user_id;
                
                printf("Enter user ID (1 for Alice, 2 for Bob): ");
                scanf("%d", &user_id);
                printf("Enter chore ID (1 for Clean dishes, 2 for Take out trash): ");
                scanf("%d", &chore_id);
                mark_as_completed(*(chores + chore_id - 1));
                printf("%s completed the chore: %s\n", users[user_id - 1]->name, chores[chore_id - 1]->description);
                update_leaderboard(leaderboard);
                display_leaderboard(leaderboard);
                break;
            }
            case 3: {
                int user_id;
                printf("Enter user ID to check achievements (1 for Alice, 2 for Bob): ");
                scanf("%d", &user_id);
                Achievement achievement = {1, "Chore Master", "Complete 2 chores", 15};
                check_achievement(*(users + user_id - 1), &achievement);
                break;
            }
            case 4:
                printf("Exiting the Family Chore Challenge. Goodbye!\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}