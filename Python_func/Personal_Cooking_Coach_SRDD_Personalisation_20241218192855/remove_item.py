def remove_item(self, item):
        if item in self.grocery_list:
            self.grocery_list.remove(item)
            print(f"Item '{item}' removed from grocery list.")
        else:
            print(f"Item '{item}' not found in grocery list.")