def main():
    print("Welcome to the Travel Itinerary Planner!")
    print("Please set your preferences for the trip.")
    # Initialize user preferences
    user_prefs = UserPreferences()
    try:
        culture = int(input("Rate your interest in culture (0-5): "))
        adventure = int(input("Rate your interest in adventure (0-5): "))
        relaxation = int(input("Rate your interest in relaxation (0-5): "))
        user_prefs.update_preferences({'culture': culture, 'adventure': adventure, 'relaxation': relaxation})
    except ValueError:
        print("Invalid input. Please enter numbers between 0 and 5.")
        return
    # Define destinations
    paris = Destination("Paris")
    paris.add_activity("Eiffel Tower", "culture", 5)
    paris.add_activity("Louvre Museum", "culture", 4)
    paris.add_activity("Seine River Cruise", "relaxation", 3)
    bali = Destination("Bali")
    bali.add_activity("Surfing", "adventure", 5)
    bali.add_activity("Yoga Retreat", "relaxation", 4)
    bali.add_activity("Ubud Monkey Forest", "adventure", 3)
    tokyo = Destination("Tokyo")
    tokyo.add_activity("Shibuya Crossing", "culture", 4)
    tokyo.add_activity("Mt. Fuji Hike", "adventure", 5)
    tokyo.add_activity("Hot Spring Bath", "relaxation", 5)
    # Initialize itinerary planner
    planner = ItineraryPlanner(user_prefs, [paris, bali, tokyo])
    # Generate and optimize itinerary
    print("\nGenerating your itinerary...")
    itinerary = planner.generate_itinerary()
    print("\nOptimizing your itinerary...")
    optimized_itinerary = planner.optimize_itinerary(itinerary)
    # Display itinerary
    print("\nHere is your optimized travel itinerary:")
    for day, activities in enumerate(optimized_itinerary, start=1):
        print(f"Day {day}:")
        for activity in activities:
            print(f" - {activity}")
    print("\nThank you for using the Travel Itinerary Planner!")