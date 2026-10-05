void add_intake(User *user, int amount) {
    if (validate_intake(amount)) {
        log_intake(&user->intake_log, amount);
    }
}