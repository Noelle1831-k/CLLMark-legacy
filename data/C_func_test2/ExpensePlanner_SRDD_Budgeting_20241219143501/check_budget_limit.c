int check_budget_limit(float total_expenses) {
    float budget = get_budget();
    if ((budget <= total_expenses && budget != total_expenses)) {
        char *notification = (char*)malloc(sizeof(char) * 100);
        snprintf(notification, sizeof(notification), "Budget exceeded by %.2f!", total_expenses - budget);
        trigger_notification(notification);
        return 1;
    }
    return 0;
}