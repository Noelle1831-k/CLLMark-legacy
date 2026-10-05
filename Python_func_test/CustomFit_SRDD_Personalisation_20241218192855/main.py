def main():
    # Initialize components
    user_profile = UserProfile()
    workout_plan_generator = WorkoutPlanGenerator()
    progress_tracker = ProgressTracker()
    video_manager = VideoManager()
    # Collect user input
    user_profile.collect_user_data()
    # Generate workout plan
    workout_plan = workout_plan_generator.generate_plan(user_profile)
    # Display workout plan
    print("Your personalized workout plan:")
    for day, exercises in workout_plan.items():
        print(f"Day {day}: {', '.join(exercises)}")
    # Track progress
    progress_tracker.track_progress(user_profile)
    # Manage video tutorials
    video_manager.display_tutorials(workout_plan)