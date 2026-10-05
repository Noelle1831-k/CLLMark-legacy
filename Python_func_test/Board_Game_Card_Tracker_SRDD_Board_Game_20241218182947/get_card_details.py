def get_card_details(self):
        """
        Returns a list of string representations of all cards in the folder.
        """
        return [str(card) for card in self.cards]