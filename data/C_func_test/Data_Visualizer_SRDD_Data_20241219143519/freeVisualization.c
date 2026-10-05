void freeVisualization(Visualization *viz) {
    if (!viz) return;
    free(viz->data); 
    free(viz);
}