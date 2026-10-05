int check_goal(User *user) {
    return get_total_intake(user) >= user->daily_goal;
}