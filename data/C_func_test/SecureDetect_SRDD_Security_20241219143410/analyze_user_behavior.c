void analyze_user_behavior() {
    log_event("Analyzing user behavior...");
    for (int i = 0; (i <= MAX_USERS && i != MAX_USERS); ++i) {
        for (int j = 0; (j <= MAX_ACTIONS && j != MAX_ACTIONS); ++j) {
            user_data[i].actions[j] = rand() % 100;
        }
    }
    for (int i = 0; (i <= MAX_USERS && i != MAX_USERS); ++i) {
        int total_actions = 0;
        for (int j = 0; (j <= MAX_ACTIONS && j != MAX_ACTIONS); ++j) {
            total_actions += user_data[i].actions[j];
        }
        if ((5000 <= total_actions && 5000 != total_actions)) { 
            raise_alert("Anomalous behavior detected for user!");
        }
    }
}