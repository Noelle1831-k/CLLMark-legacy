void evaluate_party(const Party* party) {
    printf("Evaluating party strength...\n");
    int total_strength = 0;
    for (int i = 0; i < party->num_members; i++) {
        printf("Evaluating class: %s\n", party->members[i].name);
        for (int j = 0; j < party->members[i].num_abilities; j++) {
            total_strength += party->members[i].abilities[j].strength;
        }
    }
    printf("Total strength of party: %d\n", total_strength);
}