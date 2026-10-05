def main():
    # Initialize network and database
    network = Network()
    database = Database()
    # Create users
    user1 = User("Alice", ["reading", "hiking", "coding"], "New York", "Avid reader and coder.")
    user2 = User("Bob", ["coding", "gaming", "hiking"], "San Francisco", "Gamer and outdoor enthusiast.")
    user3 = User("Charlie", ["music", "reading", "traveling"], "Los Angeles", "Music lover and traveler.")
    # Save users to database
    database.save_user(user1)
    database.save_user(user2)
    database.save_user(user3)
    # Load users from database and add to network
    for user in database.get_all_users():
        network.add_user(user)
    # Match users based on interests
    matcher = InterestMatcher(network)
    matches = matcher.find_matches()
    # Display matches
    for user, matched_users in matches.items():
        print(f"User {user.name} matches with: {[u.name for u in matched_users]}")
    # Simulate user interface
    while True:
        print("\nOptions: [1] View Matches [2] Add User [3] Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            for user, matched_users in matches.items():
                print(f"User {user.name} matches with: {[u.name for u in matched_users]}")
        elif choice == '2':
            name = input("Enter name: ")
            interests = input("Enter interests (comma-separated): ").split(',')
            location = input("Enter location: ")
            bio = input("Enter bio: ")
            new_user = User(name, interests, location, bio)
            database.save_user(new_user)
            network.add_user(new_user)
            matches = matcher.find_matches()  # Recalculate matches
        elif choice == '3':
            break
        else:
            print("Invalid choice. Please try again.")