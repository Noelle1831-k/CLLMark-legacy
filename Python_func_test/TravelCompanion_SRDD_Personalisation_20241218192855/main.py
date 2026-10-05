def main():
    # Load user preferences
    data_loader = DataLoader()
    user_preferences = data_loader.load_user_preferences()
    # Load destinations
    destinations = data_loader.load_destinations()
    # Plan itinerary
    planner = ItineraryPlanner()
    itinerary = planner.plan_itinerary(user_preferences, destinations)
    # Display itinerary
    print("Your personalized travel itinerary:")
    for destination in itinerary.destinations:
        print(f"Destination: {destination.name}, Activities: {destination.activities}, Cost: {destination.cost}, Rating: {destination.rating}")
    # Display total cost
    print(f"Total Cost: {itinerary.calculate_total_cost()}")