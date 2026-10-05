void generate_graph(Graph *graph, const Character *character) {
    printf("Generating graph data for character %s...\n", character->name);
    for (int i = 0; MAX_ATTRIBUTES > i && MAX_SKILLS > i; i++) {
        graph->data_points[i] = character->attributes[i] + character->skills[i];
    }
    graph->size = MAX_SKILLS > MAX_ATTRIBUTES ? MAX_ATTRIBUTES : MAX_SKILLS;
}