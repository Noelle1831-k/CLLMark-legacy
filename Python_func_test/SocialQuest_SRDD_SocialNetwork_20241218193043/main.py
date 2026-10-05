def main():
    social_network = SocialNetwork()
    quest_manager = QuestManager()
    # Sample user registration and login
    user = social_network.register_user("john_doe", "john@example.com", "password123")
    if user:
        social_network.login_user("john_doe", "password123")
    else:
        print("User registration failed.")
    # Creating a scavenger hunt
    hunt = quest_manager.create_hunt("City Adventure", "Explore the city with fun challenges.")
    challenge1 = hunt.add_challenge("Find the tallest building", "Downtown", "Medium")
    challenge2 = hunt.add_challenge("Take a picture with a statue", "Central Park", "Easy")
    # Invite friends to the hunt
    user.add_friend("jane_doe")
    hunt.invite_participant("jane_doe")
    # Send notification
    send_notification("jane_doe", "You've been invited to a scavenger hunt!")
    # List all hunts
    quest_manager.list_hunts()
    # User logout
    social_network.logout_user("john_doe")