def apply_effects(self, effect_type, duration):
        '''
        Applies audio effects to the playlist.
        '''
        if effect_type == "crossfade":
            self.effects.crossfade(self.playlist, duration)
        elif effect_type == "fade_in":
            self.effects.fade_in(self.playlist, duration)
        elif effect_type == "fade_out":
            self.effects.fade_out(self.playlist, duration)