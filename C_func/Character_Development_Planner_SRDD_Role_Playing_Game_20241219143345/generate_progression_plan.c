ProgressionPlan* generate_progression_plan(Character *character) {
    ProgressionPlan *plan = (ProgressionPlan*)malloc(sizeof(ProgressionPlan));
    if (plan == NULL) {
        return NULL;
    }
    plan->steps = (ProgressionStep*)malloc(MAX_STEPS * sizeof(ProgressionStep));
    if (plan->steps == NULL) {
        free(plan);
        return NULL;
    }
    plan->num_steps = 0;
    for (int i = 0; i < MAX_STEPS; i++) {
        plan->steps[i].attribute_increase = i % NUM_ATTRIBUTES;
        plan->steps[i].skill_increase = i % NUM_SKILLS;
        plan->num_steps++;
    }
    return plan;
}