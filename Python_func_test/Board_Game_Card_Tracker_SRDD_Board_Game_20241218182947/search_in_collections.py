def search_in_collections(self, card_name):
        for collection in self.collections:
            cards = collection.search_card(card_name)
            if cards:
                print(f"Found in collection {collection.name}:")
                for card in cards:
                    print(card)