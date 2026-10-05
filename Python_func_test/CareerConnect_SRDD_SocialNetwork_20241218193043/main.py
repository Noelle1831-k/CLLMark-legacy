def main():
    # Initialize users and professionals
    user1 = User("Alice", "Student", "Computer Science")
    professional1 = Professional("Bob", "Software Engineer", "Computer Science")
    professional2 = Professional("Charlie", "Data Scientist", "Data Science")
    # Store professionals in a list
    all_professionals = [professional1, professional2]
    # User creates a profile
    user1.create_profile()
    # User searches for professionals
    professionals = user1.search_professionals("Computer Science", all_professionals)
    # User sends a mentorship request
    if professionals:
        request = MentorshipRequest(user1, professionals[0])
        request.send_request()
        # Professional responds to the request
        professionals[0].accept_request(request)
        # Messaging between user and professional
        messaging = Messaging(user1, professionals[0])
        messaging.send_message("Hello, I would like to learn more about software engineering.")
        messaging.receive_message()
    # Career fair participation
    career_fair = CareerFair("Tech Career Fair")
    career_fair.participate(user1)
    career_fair.list_opportunities()
    # Workshop registration
    workshop = Workshop("AI Workshop")
    workshop.register(user1)
    workshop.list_resources()