def main():
    # Initialize the database
    db = Database()
    # Create user profiles
    user1 = User("Alice", db)
    user2 = User("Bob", db)
    user1.create_profile()
    user2.create_profile()
    # Establish network connections
    network = Network(db)
    network.add_connection(user1, user2)
    # Create and manage polls
    poll = Poll("Favorite Programming Language?", ["Python", "Java", "C++"], db)
    poll.create_poll(user1)
    # Users voting on the poll
    poll.vote(user2, "Python")
    poll.vote(user1, "Java")
    # Retrieve and display poll results
    results = poll.get_results()
    print("Poll Results:", results)
    # Share the poll within the network
    network.share_poll(user1, poll)