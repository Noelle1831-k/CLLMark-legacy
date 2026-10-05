def search_item(self, item_id):
        if item_id in self.items:
            print('Item found:', end='\n')
            print(self.items[item_id].get_item_details(), end='\n')
        else:
            print(f'Item with ID {item_id} does not exist.', end='\n')