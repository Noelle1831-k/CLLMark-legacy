FitnessMentorApp::FitnessMentorApp() {
    exerciseLibrary.push_back(Exercise("Push-up", {"Chest", "Triceps"}, "Perform a standard push-up.", "link_to_video", 1));
    exerciseLibrary.push_back(Exercise("Squat", {"Legs", "Glutes"}, "Perform a standard squat.", "link_to_video", 1));
    exerciseLibrary.push_back(Exercise("Deadlift", {"Back", "Legs"}, "Perform a standard deadlift.", "link_to_video", 3));
    exerciseLibrary.push_back(Exercise("Pull-up", {"Back", "Biceps"}, "Perform a standard pull-up.", "link_to_video", 4));
}