def add_card_to_collection(self, collection_name, card_name, quantity, condition):
        for collection in self.collections:
            if collection.name == collection_name:
                collection.add_card(card_name, quantity, condition)
                break