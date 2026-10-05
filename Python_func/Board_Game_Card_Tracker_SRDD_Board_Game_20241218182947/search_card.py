def search_card(self, card_name):
        """
        Searches for a card by its name within the collection.
        """
        return [card for card in self.cards if card.name == card_name]