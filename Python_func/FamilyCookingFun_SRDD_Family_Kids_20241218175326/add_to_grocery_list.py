def add_to_grocery_list(self, ingredients):
        self.grocery_list.add_items(ingredients)
        logging.info(f"Added to grocery list: {', '.join(ingredients)}")