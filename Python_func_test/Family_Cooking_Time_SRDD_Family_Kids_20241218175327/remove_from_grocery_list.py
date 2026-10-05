def remove_from_grocery_list(self, username, item):
        if username in self.grocery_lists:
            self.grocery_lists[username].remove_item(item)
            print(f"Removed {item} from {username}'s grocery list.")
        else:
            print(f"No grocery list found for {username}.")