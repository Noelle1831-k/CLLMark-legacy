def _apply_scope_effect(self):
        '''
        Applies the effect of the scope adjustment on the rifle's stability.
        '''
        stability_boost = self.scope_level * 2
        self.current_rifle['stability'] = min(100, self.current_rifle['stability'] + stability_boost)
        print(f"Rifle Stability after scope adjustment: {self.current_rifle['stability']}")