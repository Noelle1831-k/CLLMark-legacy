int main() {
    printf("Welcome to Fitness Buddy!\n");
    User user = create_user("John Doe", "Lose Weight", "Intermediate", "Dumbbells, Mat", 30, 3, 15);
    add_exercise("Push Up", "Chest", "Push up from the ground", "pushup_video_link", 3, 10);
    add_exercise("Squat", "Legs", "Squat down and up", "squat_video_link", 3, 12);
    add_exercise("Lunges", "Legs", "Lunge forward and alternate legs", "lunges_video_link", 3, 10);
    add_exercise("Plank", "Core", "Hold a plank position", "plank_video_link", 3, 30);
    WorkoutPlan plan = generate_plan(user);
    display_plan(plan);
    track_progress(user, plan);
    printf("Workout plan generated and progress tracked.\n");
    return 0;
}