def main():
    # Initialize users
    user1 = User("Alice", "English", "Spanish")
    user2 = User("Bob", "Spanish", "English")
    user3 = User("Charlie", "French", "English")
    user4 = User("Diana", "English", "French")
    # Initialize Language Partner system
    lp_system = LanguagePartner()
    # Add users to the system
    lp_system.add_partner(user1)
    lp_system.add_partner(user2)
    lp_system.add_partner(user3)
    lp_system.add_partner(user4)
    # Find partners
    partner1 = lp_system.find_partner(user1)
    partner2 = lp_system.find_partner(user2)
    partner3 = lp_system.find_partner(user3)
    partner4 = lp_system.find_partner(user4)
    # Initialize Chat Sessions
    chat_session1 = ChatSession(user1, partner1)
    chat_session2 = ChatSession(user2, partner2)
    chat_session3 = ChatSession(user3, partner3)
    chat_session4 = ChatSession(user4, partner4)
    # Start voice chats
    chat_session1.start_voice_chat()
    chat_session2.start_voice_chat()
    chat_session3.start_voice_chat()
    chat_session4.start_voice_chat()
    # Provide feedback
    feedback_system = Feedback()
    feedback_system.provide_feedback(user1, "Good pronunciation")
    feedback_system.provide_feedback(user2, "Excellent grammar")
    feedback_system.provide_feedback(user3, "Needs improvement in fluency")
    feedback_system.provide_feedback(user4, "Great vocabulary usage")
    # Get resources
    resource_system = Resource()
    topics = resource_system.get_conversation_topics()
    guides = resource_system.get_language_guides()
    # Print resources
    print("Conversation Topics:", topics)
    print("Language Guides:", guides)
    # End chats
    chat_session1.end_chat()
    chat_session2.end_chat()
    chat_session3.end_chat()
    chat_session4.end_chat()