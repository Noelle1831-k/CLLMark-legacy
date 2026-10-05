def remove_card_from_folder(self, card_name):
        """
        Removes a card from the folder based on its name.
        """
        self.cards = [card for card in self.cards if not (card.name == card_name)]