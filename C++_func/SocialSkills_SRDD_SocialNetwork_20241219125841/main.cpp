int main() {
    cout << "Welcome to the Social Skills Improvement App!" << endl;
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
    cout << "Thank you for using the app!" << endl;
    return 0;
}