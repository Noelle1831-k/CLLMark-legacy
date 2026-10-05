def main():
    # Initialize the leaderboard, user, and the challenges
    leaderboard = Leaderboard()
    user_name = input("Enter your name to start the fitness game: ")
    user = User(user_name)
    display_welcome_message(user_name)
    while True:
        # Main game loop
        print("\nMain Menu:")
        print("1. Start Workout")
        print("2. View Profile")
        print("3. View Leaderboard")
        print("4. Exit")
        choice = input("Select an option: ")
        if choice == "1":
            start_workout(user, leaderboard)
        elif choice == "2":
            view_profile(user)
        elif choice == "3":
            leaderboard.display_top_scores()
        elif choice == "4":
            print("Thanks for playing! Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")