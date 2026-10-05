def update(self, entity, track):
        entity.update()
        self.apply_friction(entity)