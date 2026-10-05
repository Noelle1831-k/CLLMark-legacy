def handle_input(self):
        actions = self.input_handler.get_user_input()
        if actions['move']:
            self.player.move(actions['move'])
        if actions['shoot']:
            self.player.shoot()
            self.check_collisions()