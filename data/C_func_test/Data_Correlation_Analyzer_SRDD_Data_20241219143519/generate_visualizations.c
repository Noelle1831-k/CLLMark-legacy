void generate_visualizations() {
    printf("Generating visualizations...\n");
    if (!scatter_plot() || !correlation_matrix()) {
        fprintf(stderr, "Error: Visualization generation failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Visualizations generated successfully.\n");
}