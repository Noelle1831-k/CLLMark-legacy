def main():
    # Initialize managers
    profile_manager = ProfileManager()
    chat_manager = ChatManager()
    file_manager = FileManager()
    connection_manager = ConnectionManager()
    # Example user creation
    user1 = User("Alice", "IT", "Developer", ["Python", "Java"])
    user2 = User("Bob", "IT", "Designer", ["Photoshop", "Illustrator"])
    user3 = User("Charlie", "Marketing", "Manager", ["SEO", "Content Marketing"])
    # Add users to profile manager
    profile_manager.add_user(user1)
    profile_manager.add_user(user2)
    profile_manager.add_user(user3)
    # Search for users in IT industry
    it_users = profile_manager.search_users(industry="IT")
    print("IT Users:", it_users)
    # Initiate chat between users
    chat_manager.initiate_chat(user1, user2, "Hello Bob!")
    chat_manager.initiate_chat(user2, user1, "Hi Alice, how can I help you?")
    chat_history = chat_manager.get_chat_history(user1, user2)
    print("Chat History between Alice and Bob:", chat_history)
    # Share file between users
    file_manager.share_file(user1, user2, "project.zip")
    shared_files = file_manager.get_shared_files(user2)
    print("Files shared with Bob:", shared_files)
    # Form mutual connections
    connection_manager.add_connection(user1, user2)
    connection_manager.add_connection(user2, user3)
    print("Alice's Connections:", connection_manager.get_connections(user1))
    print("Bob's Connections:", connection_manager.get_connections(user2))
    print("Charlie's Connections:", connection_manager.get_connections(user3))