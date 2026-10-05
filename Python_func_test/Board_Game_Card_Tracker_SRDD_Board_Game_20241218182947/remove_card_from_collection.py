def remove_card_from_collection(self, collection_name, card_name):
        for collection in self.collections:
            if collection.name == collection_name:
                collection.remove_card(card_name)
                break