def add_card(self, card_name, quantity, condition):
        """
        Adds a card to the collection with the specified name, quantity, and condition.
        """
        card = Card(card_name, quantity, condition)
        self.cards.append(card)