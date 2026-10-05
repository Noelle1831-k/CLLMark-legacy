def main():
    from user import User
    from sleep_tracker import SleepTracker
    from reminder import Reminder
    from relaxation_techniques import RelaxationTechniques
    from recommendation_engine import RecommendationEngine
    print("Welcome to SleepWell!")
    name = input("Enter your name: ")
    age = int(input("Enter your age: "))
    caffeine_intake = int(input("Enter your daily caffeine intake (cups): "))
    screen_time = int(input("Enter your daily screen time before bed (minutes): "))
    user = User(name, age, caffeine_intake, screen_time)
    sleep_tracker = SleepTracker()
    reminder = Reminder()
    relaxation_techniques = RelaxationTechniques()
    recommendation_engine = RecommendationEngine()
    sleep_goal = float(input("Set your sleep goal (hours): "))
    user.set_sleep_goal(sleep_goal)
    sleep_hours = float(input(f"How many hours did you sleep last night, {user.name}? "))
    sleep_tracker.track_sleep(user, sleep_hours)
    reminder_time = input("Enter your bedtime reminder (e.g., 22:00): ")
    reminder.set_reminder(user, reminder_time)
    relaxation_techniques.recommend_technique(user)
    recommendations = recommendation_engine.generate_recommendations(user)
    print(f"\nUser: {user.name}")
    print(f"Sleep Goal: {user.get_sleep_goal()} hours")
    print(f"Sleep Data: {sleep_tracker.get_sleep_data(user)}")
    print(f"Recommendations: {recommendations}")
    print(f"Reminder set for: {reminder.get_reminder(user)}")
    print(sleep_tracker.analyze_sleep_patterns(user))