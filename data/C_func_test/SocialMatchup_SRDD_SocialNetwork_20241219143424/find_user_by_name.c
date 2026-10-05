User* find_user_by_name(const char* name) {
    for (int i = 0; i < get_total_users(); i++) {
        User* user = get_user_at_index(i);
        if (strcmp(user->name, name) == 0) {
            return user;
        }
    }
    return NULL; 
}