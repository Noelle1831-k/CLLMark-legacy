int main(int argc, char *argv[]) {
    printf("Welcome to the Social Skills Improvement App!\n");
    User user;
    user.registerUser();
    Exercise exercise;
    exercise.loadExercise();
    exercise.completeExercise();
    Community community;
    community.connectUsers();
    community.shareExperience();
    community.supportOthers();
    Feedback feedback;
    feedback.generateFeedback();
    printf("Thank you for using the app!\n");
    return 0;
}