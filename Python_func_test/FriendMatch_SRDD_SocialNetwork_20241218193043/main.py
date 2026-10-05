def main():
    # Initialize components
    user_profile = UserProfile()
    friend_matcher = FriendMatcher()
    communication = Communication()
    activity_planner = ActivityPlanner()
    # Example workflow
    user_profile.create_profile("Alice", ["hiking", "reading"], ["outgoing", "friendly"])
    user_profile.create_profile("Bob", ["reading", "gaming"], ["introverted", "thoughtful"])
    user_profile.create_profile("Charlie", ["hiking", "gaming"], ["adventurous", "friendly"])
    # Add profiles to the friend matcher
    for name in user_profile.profiles.keys():
        friend_matcher.add_user_profile(name, user_profile.get_profile_data(name))
    matches = friend_matcher.find_matches(user_profile.get_profile_data("Alice"))
    print("Potential Matches for Alice:", matches)
    if matches:
        communication.initiate_conversation("Alice", matches[0])
        communication.send_message("Alice", matches[0], "Hi, would you like to go hiking?")
        response = communication.receive_message(matches[0], "Alice")
        print("Response from", matches[0], ":", response)
        activity_planner.create_activity("Alice", matches[0], "Hiking at Blue Mountain")
        activities = activity_planner.get_activities("Alice")
        print("Planned Activities for Alice:", activities)