def main():
    # Create users
    user1 = User("Alice", 30, 70, 165)
    user2 = User("Bob", 35, 80, 175)
    user3 = User("Charlie", 10, 40, 140)
    # Create family
    family = Family("The Smiths")
    family.add_member(user1)
    family.add_member(user2)
    family.add_member(user3)
    # Create activities
    activity1 = Activity("Running", "Medium", 30)
    activity2 = Activity("Cycling", "Hard", 45)
    activity3 = Activity("Swimming", "Easy", 60)
    # Create challenge
    challenge = Challenge("Weekend Warrior", "Complete a series of activities over the weekend", [activity1, activity2, activity3])
    # Create video tutorials
    video_tutorial1 = VideoTutorial("How to Run Properly", "http://example.com/run")
    video_tutorial2 = VideoTutorial("Cycling Tips for Beginners", "http://example.com/cycle")
    # Create fitness tips
    fitness_tip1 = FitnessTip("Stay hydrated during workouts.")
    fitness_tip2 = FitnessTip("Warm up before starting any exercise.")
    # Create motivational messages
    motivational_message1 = MotivationalMessage("Keep pushing your limits!")
    motivational_message2 = MotivationalMessage("You are stronger than you think!")
    # Start challenge
    challenge.start_challenge()
    # Update user progress
    user1.update_progress(activity1, 30)
    user2.update_progress(activity2, 45)
    user3.update_progress(activity3, 60)
    # Track family progress
    family.track_family_progress()
    # Set family goal
    family.set_family_goal("Complete 5 activities this week")
    # Reward family
    family.reward_family()
    # Play video tutorials
    video_tutorial1.play_video()
    video_tutorial2.play_video()
    # Get fitness tips
    print(fitness_tip1.get_tip())
    print(fitness_tip2.get_tip())
    # Get motivational messages
    print(motivational_message1.get_message())
    print(motivational_message2.get_message())