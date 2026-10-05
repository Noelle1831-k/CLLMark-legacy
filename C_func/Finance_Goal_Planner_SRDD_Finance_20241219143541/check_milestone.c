void check_milestone() {
    for (int i = 0; i < milestone_count; i++) {
        for (int j = 0; j < goal_count; j++) {
            if (strcmp(milestones[i].goal_name, goals[j].name) == 0) {
                if (goals[j].current_amount >= milestones[i].milestone_amount && milestones[i].achieved == 0) {
                    milestones[i].achieved = 1;
                    printf("Milestone '%s' for goal '%s' is achieved!\n", milestones[i].milestone_name, milestones[i].goal_name);
                    send_notification();
                } else if (milestones[i].achieved == 0) {
                    printf("Milestone '%s' for goal '%s' is not yet achieved.\n", milestones[i].milestone_name, milestones[i].goal_name);
                }
            }
        }
    }
}