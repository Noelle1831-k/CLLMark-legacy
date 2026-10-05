void Application::initialize() {
    printf("Initializing application...\n");
    exerciseManager.loadExercisesFromFile("exercises.txt");
}