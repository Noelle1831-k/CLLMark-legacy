def main():
    '''
    Main function to run the application.
    '''
    data_file = 'user_data.json'
    user_data = load_data(data_file)
    user = User(user_data.get('name', 'Default User'), user_data.get('routines', []))
    recommendation_engine = RecommendationEngine()
    while True:
        print("\n1. Add Routine\n2. Remove Routine\n3. Update Routine\n4. View Progress\n5. Get Recommendations\n6. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            routine_name = input("Enter routine name: ")
            user.add_routine(routine_name)
        elif choice == '2':
            routine_name = input("Enter routine name to remove: ")
            user.remove_routine(routine_name)
        elif choice == '3':
            routine_name = input("Enter routine name to update: ")
            user.update_routine(routine_name)
        elif choice == '4':
            stats = calculate_statistics(user.routines)
            print(f"Routine Statistics: {stats}")
        elif choice == '5':
            recommendations = recommendation_engine.generate_recommendations(user.to_dict())
            for rec in recommendations:
                send_notification(rec)
        elif choice == '6':
            save_data(data_file, user.to_dict())
            break
        else:
            print("Invalid choice. Please try again.")