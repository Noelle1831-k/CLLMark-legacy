def main():
    # Initialize components
    user_profiles = []
    health_metrics = HealthMetrics()
    appointment_scheduler = AppointmentScheduler()
    health_articles = HealthArticles()
    goal_manager = GoalManager()
    notification_system = NotificationSystem()
    # Example of creating user profiles
    user_profiles.append(UserProfile("John Doe", 30, "Male"))
    user_profiles.append(UserProfile("Jane Doe", 28, "Female"))
    # Example of adding health metrics
    for profile in user_profiles:
        health_metrics.add_metric(profile, "weight", 70)
        health_metrics.add_metric(profile, "height", 175)
        health_metrics.add_metric(profile, "blood_pressure", "120/80")
    # Schedule an appointment
    appointment_scheduler.schedule_appointment(user_profiles[0], "Doctor Visit", "2023-11-15")
    # Set a health goal
    goal_manager.set_goal(user_profiles[0], "Lose 5 kg", "2023-12-31")
    # Send notifications
    notification_system.send_reminder(user_profiles[0], "Time for your daily exercise!")
    # Display health articles
    health_articles.display_articles()