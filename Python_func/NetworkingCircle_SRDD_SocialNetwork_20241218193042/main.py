def main():
    # Initialize the network
    network = Network()
    # Create users
    alice = User("Alice", "Software Development")
    bob = User("Bob", "Software Development")
    charlie = User("Charlie", "Data Science")
    diana = User("Diana", "Data Science")
    # Add users to the network
    network.add_user(alice)
    network.add_user(bob)
    network.add_user(charlie)
    network.add_user(diana)
    # Connect users
    network.connect_users(alice, bob)
    network.connect_users(charlie, diana)
    # Send messages
    message1 = Message(alice, bob, "Hello Bob, let's collaborate on a project!", network)
    message2 = Message(charlie, diana, "Hi Diana, I have some data insights to share.", network)
    message1.send()
    message2.send()
    # Create industry groups
    software_group = IndustryGroup("Software Development")
    data_science_group = IndustryGroup("Data Science")
    software_group.add_member(alice)
    software_group.add_member(bob)
    data_science_group.add_member(charlie)
    data_science_group.add_member(diana)
    # Display connections and messages
    network.display_connections()
    network.display_messages()