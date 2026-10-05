void init_app(SleepTrackerApp *app) {
    init_user(&app->user, "John Doe", 30, "No caffeine after 6 PM");
    init_analyzer(&app->analyzer);
}