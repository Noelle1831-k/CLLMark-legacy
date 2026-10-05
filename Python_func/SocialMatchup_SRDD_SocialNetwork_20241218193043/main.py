def main():
    # Initialize components
    user_profiles = []
    conversations = []
    project_ideas = ProjectIdeas()
    # Create sample users
    user1 = UserProfile("Alice", ["Python", "Machine Learning"], ["AI", "Data Science"])
    user2 = UserProfile("Bob", ["JavaScript", "Web Development"], ["Frontend", "UI/UX"])
    user_profiles.extend([user1, user2])
    # Matching users with a threshold of 2
    matcher = MatchingAlgorithm(user_profiles, compatibility_threshold=2)
    matches = matcher.find_matches(user1)
    # Initiate conversation
    if matches:
        conversation = Conversation(user1, matches[0])
        conversations.append(conversation)
        conversation.send_message("Hello! Let's collaborate on a project.")
    # Share project ideas
    project_ideas.add_idea(user1, "AI-based Web App")
    project_ideas.add_idea(user2, "Responsive Design Framework")
    # Display project ideas
    project_ideas.display_ideas()