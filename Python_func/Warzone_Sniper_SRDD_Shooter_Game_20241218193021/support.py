def support(self, player):
        # Provide support based on player's status
        if player.health < 50:
            print("Squad is providing medical support to the player...")
        else:
            print("Squad is providing cover fire...")