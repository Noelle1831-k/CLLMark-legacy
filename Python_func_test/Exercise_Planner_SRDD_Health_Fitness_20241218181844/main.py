def main():
    # Get user details
    name = input("Enter your name: ")
    age = int(input("Enter your age: "))
    gender = input("Enter your gender: ")
    # Initialize user
    user = User(name, age, gender)
    # Get user fitness goals
    print("Select your fitness goal:")
    print("1. Weight Loss")
    print("2. Muscle Gain")
    print("3. Overall Fitness Improvement")
    goal_choice = input("Enter the number corresponding to your goal: ")
    if goal_choice == "1":
        user.set_goals("weight loss")
    elif goal_choice == "2":
        user.set_goals("muscle gain")
    elif goal_choice == "3":
        user.set_goals("overall fitness improvement")
    else:
        print("Invalid choice. Defaulting to overall fitness improvement.")
        user.set_goals("overall fitness improvement")
    # Initialize exercises
    exercises = [
        Exercise("Push-up", "Chest", "Intermediate", 3, 15),
        Exercise("Squat", "Legs", "Beginner", 3, 20),
        Exercise("Plank", "Core", "Advanced", 3, 60),
        Exercise("Deadlift", "Back", "Advanced", 4, 10),
        Exercise("Bicep Curl", "Arms", "Intermediate", 3, 12),
        Exercise("Lunges", "Legs", "Beginner", 3, 15)
    ]
    # Generate exercise plan
    exercise_plan = ExercisePlan(user)
    exercise_plan.generate_plan(exercises)
    # Schedule exercises
    scheduler = Scheduler(exercise_plan)
    scheduler.schedule_exercises()
    # Initialize notifications
    notification = Notification(user)
    notification.send_reminder("Time for your workout!")
    # Print the exercise plan and schedule
    print("Exercise Plan:")
    for exercise in exercise_plan.get_plan():
        print(exercise.get_exercise_info())
    print("\nSchedule:")
    for schedule in scheduler.get_schedule():
        print(schedule)