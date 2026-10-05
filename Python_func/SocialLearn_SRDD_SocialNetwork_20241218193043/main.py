def main():
    # Create users
    alice = User("Alice", "alice@example.com")
    bob = User("Bob", "bob@example.com")
    charlie = User("Charlie", "charlie@example.com")
    # Add interests
    alice_interest = Interest("Python Programming")
    bob_interest = Interest("Data Science")
    charlie_interest = Interest("Machine Learning")
    alice.add_interest(alice_interest)
    bob.add_interest(bob_interest)
    charlie.add_interest(charlie_interest)
    # Connect users
    alice.connect_with_users(bob)
    bob.connect_with_users(charlie)
    alice.connect_with_users(charlie)
    # Create study group
    python_group = StudyGroup("Python Enthusiasts")
    python_group.join_group(alice)
    python_group.join_group(bob)
    python_group.join_group(charlie)
    # Share resources
    python_group.share_resources("Python for Beginners eBook")
    python_group.share_resources("Advanced Python Tutorials")
    # Create course
    python_course = Course("Advanced Python", "Dr. Smith")
    python_course.enroll_user(alice)
    python_course.enroll_user(bob)
    python_course.enroll_user(charlie)
    # Conduct webinar
    python_course.conduct_webinar()
    # Start discussion
    discussion = Discussion("Python Best Practices")
    discussion.start_discussion()
    discussion.post_comment(alice, "I love Python!")
    discussion.post_comment(bob, "Python is great for data science.")
    discussion.post_comment(charlie, "Python is versatile and powerful.")