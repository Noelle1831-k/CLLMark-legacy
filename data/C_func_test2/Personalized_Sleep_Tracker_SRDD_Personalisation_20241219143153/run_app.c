void run_app(SleepTrackerApp *app) {
    add_entry(&app->sleep_data[0], "2023-10-01", 8, "No caffeine, exercised");
    app->analyzer.data[app->analyzer.count++] = app->sleep_data[0];
    analyze_data(&app->analyzer);
    generate_recommendations(&app->analyzer);
}