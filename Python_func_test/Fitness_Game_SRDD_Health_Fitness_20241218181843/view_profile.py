def view_profile(user):
    """
    Displays the user's profile with statistics.
    """
    print(f"\nUser Profile: {user.get_stats()}")