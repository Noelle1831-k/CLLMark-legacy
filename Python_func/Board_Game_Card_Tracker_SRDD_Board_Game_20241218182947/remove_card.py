def remove_card(self, card_name):
        """
        Removes a card from the collection based on its name.
        """
        self.cards = [card for card in self.cards if card.name != card_name]