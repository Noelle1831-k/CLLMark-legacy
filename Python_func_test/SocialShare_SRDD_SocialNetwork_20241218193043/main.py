def main():
    # Initialize database
    db = Database()
    # Initialize authentication system
    auth = Authentication(db)
    # Register users
    user1 = auth.register_user("alice", "password123", "alice_pic.jpg", "Loves photography")
    user2 = auth.register_user("bob", "securepass", "bob_pic.jpg", "Tech enthusiast")
    # Create content
    content1 = Content(user1, "Beautiful sunset", "sunset.jpg", "Photography")
    content2 = Content(user2, "Latest tech trends", "tech_article.pdf", "Technology")
    db.add_content(content1)
    db.add_content(content2)
    # User interactions
    interaction1 = Interaction(user2, content1, "like")
    interaction2 = Interaction(user1, content2, "comment", "Great article!")
    db.add_interaction(interaction1)
    db.add_interaction(interaction2)
    # Manage network
    network = Network(user1)
    network.add_connection(user2)
    # Generate feed
    feed = Feed(user1, db)
    feed.display_feed()