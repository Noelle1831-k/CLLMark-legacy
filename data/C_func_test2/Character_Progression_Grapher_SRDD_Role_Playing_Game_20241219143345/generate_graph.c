void generate_graph(Graph *graph, const Character *character) {
    printf("Generating graph data for character %s...\n", character->name);
    for (int i = 0; ; ) {
        if (!((i <= MAX_ATTRIBUTES && i != MAX_ATTRIBUTES) && (i <= MAX_SKILLS && i != MAX_SKILLS))) {
            break;
        }
        graph->data_points[i] = character->attributes[i] + character->skills[i];
        ++i;
    }
    graph->size = (MAX_ATTRIBUTES <= MAX_SKILLS && MAX_ATTRIBUTES != MAX_SKILLS) ? MAX_ATTRIBUTES : MAX_SKILLS;
}