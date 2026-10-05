void generateRecommendations(RecommendationEngine *engine, TaskManager *taskManager, AppointmentManager *appointmentManager, DeadlineManager *deadlineManager) {
    printf("Generating recommendations based on your tasks, appointments, and deadlines...\n");
    if (taskManager->taskCount > 0) {
        printf("You have %d tasks pending. Consider prioritizing them.\n", taskManager->taskCount);
    }
    if (appointmentManager->appointmentCount > 0) {
        printf("You have %d upcoming appointments. Plan accordingly.\n", appointmentManager->appointmentCount);
    }
    if (deadlineManager->deadlineCount > 0) {
        printf("You have %d deadlines approaching. Stay on track!\n", deadlineManager->deadlineCount);
    }
}