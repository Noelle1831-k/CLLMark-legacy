def adjust_scope(self):
        '''
        Adjusts the rifle's scope to improve accuracy.
        '''
        print("Adjusting scope...")
        self.scope_level += random.randint(1, 3)
        print(f"Scope Level: {self.scope_level}")
        self._apply_scope_effect()