def add_item(self, item):
        if item not in self.grocery_list:
            self.grocery_list.append(item)
            print(f"Item '{item}' added to grocery list.")
        else:
            print(f"Item '{item}' already in grocery list.")