def add_to_grocery_list(self, username, item):
        if username in self.grocery_lists:
            self.grocery_lists[username].add_item(item)
            print(f"Added {item} to {username}'s grocery list.")
        else:
            print(f"No grocery list found for {username}.")