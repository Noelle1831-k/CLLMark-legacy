def apply_friction(self, entity):
        friction = 0.1
        entity.velocity[0] *= (1 - friction)
        entity.velocity[1] *= (1 - friction)