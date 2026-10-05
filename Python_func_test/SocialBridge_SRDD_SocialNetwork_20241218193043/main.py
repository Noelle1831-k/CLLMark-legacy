def main():
    # Initialize the database
    db = Database()
    # Create some users
    student = User("Alice", "Student", "alice@example.com", "Computer Science")
    professional = User("Bob", "Professional", "bob@example.com", "Software Engineering")
    # Add users to the database
    db.add_user(student)
    db.add_user(professional)
    # Search for professionals
    search_engine = SearchEngine(db)
    professionals = search_engine.search_professionals("Software Engineering")
    # Request mentorship
    mentorship_request = MentorshipRequest(student, professional)
    mentorship_request.send_request()
    # Professional accepts the request
    mentorship_request.accept_request()
    # Messaging between users
    messaging = Messaging(student, professional)
    messaging.send_message("Hello, I would like to learn more about software engineering.")
    # Access resources
    resource_access = ResourceAccess(student)
    resource_access.access_resource("Python Programming Guide")
    # Participate in a career fair
    career_fair = CareerFair()
    career_fair.participate(student)