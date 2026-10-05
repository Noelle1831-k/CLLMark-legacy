void recommend_party(const Party* party) {
    printf("Recommending the best party combination...\n");
    printf("Best combination for your party:\n");
    for (int i = 0; i < party->num_members; i++) {
        printf("Class %d: %s\n", i + 1, party->members[i].name);
    }
}