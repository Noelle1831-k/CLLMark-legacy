def player_action(self, level):
        '''
        Handle player actions based on user input.
        '''
        action = self.ui.get_player_action()
        if action == 'shoot':
            target_hit = level.shoot_target(self.player.weapon)
            if target_hit:
                self.player.earn_points(target_hit.points)
                self.ui.display_score(self.player.score)
        elif action == 'upgrade':
            self.player.unlock_weapon()
            self.ui.display_weapon_upgrade(self.player.weapon)