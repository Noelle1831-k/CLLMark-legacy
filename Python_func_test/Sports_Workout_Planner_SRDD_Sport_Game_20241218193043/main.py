def main():
    # User authentication
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    user = User(username=username, password=password)
    # Set sport and training goals
    sport = input("Enter your sport of choice: ")
    goals = input("Enter your training goals: ")
    user.set_sport(sport)
    user.set_training_goals(goals)
    # Generate workout plan
    user.generate_workout_plan()
    # Record progress
    date = input("Enter the date of your workout (YYYY-MM-DD): ")
    progress = input("Enter your workout progress: ")
    user.record_progress(date, progress)
    # Generate report
    report = user.generate_report()
    print(report)
    # Get technique tips
    exercise_name = input("Enter the exercise name for tips: ")
    guide = TechniqueGuide()
    tips = guide.get_tips(exercise_name)
    print(tips)