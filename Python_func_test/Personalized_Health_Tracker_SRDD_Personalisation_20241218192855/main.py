def main():
    '''
    Entry point of the application. Initializes components and runs the application loop.
    '''
    storage = DataStorage('user_data.json')
    user_data = storage.load_data()
    if user_data:
        user = User(**user_data)
    else:
        user = User(name='John Doe', age=30, weight=70, height=175, activity_level='moderate', nutrition_intake='balanced')
    tracker = HealthTracker(user)
    while True:
        print("\nHealth Tracking Application")
        print("1. View Health Data")
        print("2. Update Health Data")
        print("3. Generate Recommendations")
        print("4. Save and Exit")
        choice = input("Enter your choice: ").strip()
        if choice == '1':
            print(user.get_data())
        elif choice == '2':
            update_user_data(user)
        elif choice == '3':
            print(tracker.generate_recommendations())
        elif choice == '4':
            storage.save_data(user.get_data())
            print("Data saved successfully. Exiting application.")
            break
        else:
            print("Invalid choice. Please try again.")