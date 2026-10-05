def check_collision(self, obj1, obj2):
        return obj1.position.distance_to(obj2.position) < 10