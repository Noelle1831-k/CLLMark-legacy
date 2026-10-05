def main():
    # Initialize the network
    network = Network()
    # Create users
    user1 = User("Alice", "alice@example.com")
    user2 = User("Bob", "bob@example.com")
    user3 = User("Charlie", "charlie@example.com")
    # User1 creates a profile
    user1.create_profile("Alice", "I love streaming!")
    # User1 starts a livestream
    stream1 = Livestream(user1)
    stream1.start_stream("Alice's Cooking Show")
    # User2 and User3 follow User1
    network.add_follower(user1, user2)
    network.add_follower(user1, user3)
    # Display followers of User1
    followers = network.get_followers(user1)
    print(f"Followers of {user1.name}: {[follower.name for follower in followers]}")
    # User2 interacts with the livestream
    interaction = Interaction()
    interaction.add_comment(stream1, user2, "Great show!")
    interaction.add_reaction(stream1, user2, "like")
    # User3 interacts with the livestream
    interaction.add_comment(stream1, user3, "Can't wait to try this recipe!")
    interaction.add_reaction(stream1, user3, "love")
    # End the livestream
    stream1.end_stream()
    # User2 unfollows User1
    network.remove_follower(user1, user2)
    # Display updated followers of User1
    followers = network.get_followers(user1)
    print(f"Updated followers of {user1.name}: {[follower.name for follower in followers]}")