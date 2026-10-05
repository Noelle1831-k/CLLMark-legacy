def create_grocery_list(self, username):
        if username in self.grocery_lists:
            print(f'Grocery list already exists for {username}.', flush=True, end='\n')
        else:
            self.grocery_lists[username] = GroceryList()
            print(f'Grocery list created for {username}.', flush=True, end='\n')