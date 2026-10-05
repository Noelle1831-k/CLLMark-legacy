def main():
    # Initialize components
    users = {}
    exercises = [Exercise("Active Listening"), Exercise("Empathy Building"), Exercise("Communication Skills")]
    community = Community()
    feedback_system = Feedback()
    progress_tracker = ProgressTracker()
    # Simulate user interactions
    while True:
        print("\nWelcome to SocialSkill!")
        username = input("Enter your username: ").strip()
        if not username:
            print("Username cannot be empty. Please try again.")
            continue
        if username not in users:
            users[username] = User(username)
        user = users[username]
        print("\nOptions:")
        print("1. Perform Exercise")
        print("2. View Progress")
        print("3. Set Goals")
        print("4. Join Community")
        print("5. Exit")
        choice = input("Choose an option: ").strip()
        if choice == '1':
            for i, exercise in enumerate(exercises):
                print(f"{i+1}. {exercise.name}")
            try:
                exercise_choice = int(input("Choose an exercise: ").strip()) - 1
                if 0 <= exercise_choice < len(exercises):
                    result = exercises[exercise_choice].perform()
                    feedback = feedback_system.generate_feedback(result)
                    print(feedback)
                    progress_tracker.log_activity(user, exercises[exercise_choice].name, result)
                else:
                    print("Invalid choice. Please select a valid exercise number.")
            except ValueError:
                print("Invalid input. Please enter a number.")
        elif choice == '2':
            report = progress_tracker.generate_report(user)
            print(report)
        elif choice == '3':
            goal = input("Enter your new goal: ").strip()
            if goal:
                user.set_goal(goal)
            else:
                print("Goal cannot be empty.")
        elif choice == '4':
            community.join(user)
        elif choice == '5':
            print("Exiting SocialSkill. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")