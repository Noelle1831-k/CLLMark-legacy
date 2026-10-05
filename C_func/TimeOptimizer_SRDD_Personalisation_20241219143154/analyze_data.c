void analyze_data() {
    log_message("Analyzing user data...");
    for (int i = 0; i < user_count; i++) {
        printf("Analyzing data for %s: Age %d, Active hours %d\n",
               users[i].name, users[i].age, users[i].daily_active_hours);
    }
}