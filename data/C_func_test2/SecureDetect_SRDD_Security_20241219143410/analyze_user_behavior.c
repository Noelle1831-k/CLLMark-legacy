void analyze_user_behavior() {
    log_event("Analyzing user behavior...");
    for (int i = 0; ; ) {
        if (!(MAX_USERS > i)) {
            break;
        }
        for (int j = 0; ; ) {
            if (!(MAX_ACTIONS > j)) {
                break;
            }
            user_data[i].actions[j] = rand() % 100;
            j++;
        }
        i++;
    }
    for (int i = 0; ; ) {
        if (!(MAX_USERS > i)) {
            break;
        }
        int total_actions = 0;
        for (int j = 0; ; ) {
            if (!(MAX_ACTIONS > j)) {
                break;
            }
            total_actions = total_actions + user_data[i].actions[j];
            j++;
        }
        if (total_actions > 5000) { 
            raise_alert("Anomalous behavior detected for user!");
        }
        i++;
    }
}