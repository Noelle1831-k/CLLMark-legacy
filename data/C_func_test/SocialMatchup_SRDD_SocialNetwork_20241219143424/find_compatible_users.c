int find_compatible_users(const User* user, User* matches[]) {
    int count = 0;
    for (int i = 0; i < get_total_users(); i++) {
        User* candidate = get_user_at_index(i);
        if (is_compatible(user, candidate)) {
            matches[count++] = candidate;
        }
    }
    return count;
}