def generate_objectives(self):
        objectives = []
        for _ in range(random.randint(3, 7)):
            position = (random.randint(0, self.width), random.randint(0, self.height))
            type = random.choice(["Flag", "Control Point", "Resource"])
            objectives.append(Objective(position, type))
        return objectives