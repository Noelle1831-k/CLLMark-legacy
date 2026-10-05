void mark_as_completed(Chore* chore) {
    if (chore->assigned_user != NULL) {
        add_points(chore->assigned_user, chore->points);
    }
}