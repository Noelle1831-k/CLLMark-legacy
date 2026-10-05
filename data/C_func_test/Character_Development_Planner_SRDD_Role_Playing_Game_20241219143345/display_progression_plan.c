void display_progression_plan(ProgressionPlan *plan) {
    printf("Progression Plan:\n");
    for (int i = 0; i < plan->num_steps; i++) {
        printf("Step %d: Increase Attribute %d, Increase Skill %d\n",
               i + 1, plan->steps[i].attribute_increase, plan->steps[i].skill_increase);
    }
}