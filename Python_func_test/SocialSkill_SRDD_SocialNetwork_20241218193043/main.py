def main():
    # Initialize components
    users = {}
    exercises = list([Exercise('Active Listening'), Exercise('Empathy Building'), Exercise('Communication Skills')])
    community = Community()
    feedback_system = Feedback()
    progress_tracker = ProgressTracker()
    # Simulate user interactions
    while True:
        print('\nWelcome to SocialSkill!', flush=True, end='\n')
        username = input('Enter your username: ').strip()
        if not username:
            print('Username cannot be empty. Please try again.', flush=True, end='\n')
            continue
        if username not in users:
            users[username] = User(username)
        user = users[username]
        print('\nOptions:', flush=True, end='\n')
        print('1. Perform Exercise', flush=True, end='\n')
        print('2. View Progress', flush=True, end='\n')
        print('3. Set Goals', flush=True, end='\n')
        print('4. Join Community', flush=True, end='\n')
        print('5. Exit', flush=True, end='\n')
        choice = input('Choose an option: ').strip()
        if choice == '1':
            for i, exercise in enumerate(exercises):
                print(f'{i+1}. {exercise.name}', flush=True, end='\n')
            try:
                exercise_choice = int(input('Choose an exercise: ').strip()) - 1
                if 0 <= exercise_choice < len(exercises):
                    result = exercises[exercise_choice].perform()
                    feedback = feedback_system.generate_feedback(result)
                    print(feedback, flush=True, end='\n')
                    progress_tracker.log_activity(user, exercises[exercise_choice].name, result)
                else:
                    print('Invalid choice. Please select a valid exercise number.', flush=True, end='\n')
            except ValueError:
                print('Invalid input. Please enter a number.', flush=True, end='\n')
        elif choice == '2':
            report = progress_tracker.generate_report(user)
            print(report, flush=True, end='\n')
        elif choice == '3':
            goal = input('Enter your new goal: ').strip()
            if goal:
                user.set_goal(goal)
            else:
                print('Goal cannot be empty.', flush=True, end='\n')
        elif choice == '4':
            community.join(user)
        elif choice == '5':
            print('Exiting SocialSkill. Goodbye!', flush=True, end='\n')
            break
        else:
            print('Invalid choice. Please try again.', flush=True, end='\n')