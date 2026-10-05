def main():
    planner = SportPlanner()
    ui = UserInterface(planner)
    while True:
        print("\n--- Sports Planner Menu ---")
        print("1. Add Sport")
        print("2. View Sport")
        print("3. Exit")
        choice = input("Enter choice: ")
        if choice == '1':
            sport_name = input("Enter sport name: ")
            planner.add_sport(sport_name)
        elif choice == '2':
            sport_name = input("Enter sport name: ")
            sport = planner.get_sport(sport_name)
            if sport:
                ui.display_sport(sport)
            else:
                print("Sport not found.")
        elif choice == '3':
            print("Exiting the Sports Planner. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")