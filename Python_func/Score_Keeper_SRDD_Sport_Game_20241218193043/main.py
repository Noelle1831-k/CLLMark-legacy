def main():
    ui = UserInterface()
    game_tracker = GameTracker()
    while True:
        ui.display_menu()
        choice = ui.get_user_input("Choose an option: ")
        if choice == '1':
            team_name = ui.get_user_input("Enter team name: ")
            game_tracker.add_team(team_name)
        elif choice == '2':
            team_name = ui.get_user_input("Enter team name: ")
            score = int(ui.get_user_input("Enter score: "))
            game_tracker.update_score(team_name, score)
        elif choice == '3':
            scores = game_tracker.get_scores()
            ui.update_display(scores, game_tracker.get_time_played())
        elif choice == '4':
            game_tracker.timer.stop()
            scores = game_tracker.get_scores()
            ui.update_display(scores, game_tracker.get_time_played())
            print("Exiting the game. Thank you for using the Sports Game Tracker!")
            break
        else:
            print("Invalid choice. Please try again.")