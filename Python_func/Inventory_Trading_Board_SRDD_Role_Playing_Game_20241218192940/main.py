def main():
    print("Welcome to the RPG Marketplace!")
    users = []
    items = []
    marketplace = Marketplace(users, items)
    search_engine = SearchEngine(items)
    messaging_system = MessagingSystem(users)
    rating_system = RatingSystem(users)
    # Sample actions
    user1 = User("player1", "password123", "Player One", balance=1000)
    user2 = User("player2", "password456", "Player Two", balance=500)
    users.extend([user1, user2])
    user1.register(users)
    user2.register(users)
    item1 = Item("Sword of Destiny", "A powerful sword.", 500, user1.username)
    item2 = Item("Shield of Valor", "An unbreakable shield.", 300, user2.username)
    items.extend([item1, item2])
    marketplace.list_item(item1)
    marketplace.list_item(item2)
    print("Searching for items with price <= 400...")
    search_results = search_engine.search_items(max_price=400)
    for item in search_results:
        print(item)
    print("Messaging system: Sending a message from user1 to user2")
    messaging_system.send_message(user1.username, user2.username, "Interested in your shield. Let's trade!")
    print("User2 rating User1...")
    rating_system.rate_user(user2.username, user1.username, 5)
    print("Processing trade: User2 buying Sword of Destiny...")
    marketplace.process_trade(user2, "Sword of Destiny")