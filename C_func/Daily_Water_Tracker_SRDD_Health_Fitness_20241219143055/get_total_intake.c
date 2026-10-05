int get_total_intake(User *user) {
    return get_intake(&user->intake_log);
}