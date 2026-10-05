int main() {
    Character character;
    Graph graph;
    UserInterface ui;
    FileHandler fileHandler;
    init_character(&character);
    init_graph(&graph);
    init_user_interface(&ui);
    init_file_handler(&fileHandler);
    printf("Welcome to the Character Progression Grapher!\n");
    if (load_character_data(&fileHandler, &character)) {
        printf("Character data successfully loaded.\n");
        get_user_input(&ui, &character);
        generate_graph(&graph, &character);
        customize_graph(&graph);
        display_graph(&ui, &graph);
        save_graph_data(&fileHandler, &graph);
    } else {
        fprintf(stderr, "Error: Unable to load character data. Please check your files.\n");
    }
    printf("Exiting application. Thank you for using the Character Progression Grapher!\n");
    return 0;
}