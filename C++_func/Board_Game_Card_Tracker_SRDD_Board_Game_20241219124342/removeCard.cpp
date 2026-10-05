void removeCard(string cardName) {
        cards.erase(
            remove_if(cards.begin(), cards.end(), [&](Card &card) { return card.getName() == cardName; }),
            cards.end());
    }