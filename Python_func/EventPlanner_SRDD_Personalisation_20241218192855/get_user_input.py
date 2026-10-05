def get_user_input(self):
        event_type = input("Enter the type of event (e.g., wedding, conference): ")
        guest_count = int(input("Enter the number of guests: "))
        budget = float(input("Enter your budget: "))
        date = input("Enter the preferred date (YYYY-MM-DD): ")
        venue = input("Enter the preferred venue: ")
        preferences = input("Enter any specific requirements or preferences: ")
        return EventDetails(event_type, guest_count, budget, date, venue, preferences)