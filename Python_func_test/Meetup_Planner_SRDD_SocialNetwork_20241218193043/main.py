def main():
    users = []
    events = []
    interests = []
    locations = []
    messages = []
    # Initialize components
    user_manager = User(users)
    event_manager = Event(events)
    interest_manager = Interest(interests)
    location_manager = Location(locations)
    messaging_service = Messaging(messages)
    search_service = Search(events, interests, locations)
    # Simulate user interactions
    user_manager.register_user("Alice", "alice@example.com", "password123")
    user_manager.register_user("Bob", "bob@example.com", "password456")
    event_manager.create_event("Python Meetup", "2023-11-01", "18:00", "Central Park", ["Python", "Networking"])
    event_manager.create_event("JavaScript Conference", "2023-11-05", "09:00", "Tech Hub", ["JavaScript", "Development"])
    interest_manager.add_interest("Python")
    interest_manager.add_interest("JavaScript")
    location_manager.add_location("Central Park")
    location_manager.add_location("Tech Hub")
    messaging_service.send_message("Alice", "Bob", "Looking forward to the meetup!")
    messaging_service.send_message("Bob", "Alice", "Me too!")
    search_service.search_by_interest("Python")
    search_service.search_by_location("Central Park")