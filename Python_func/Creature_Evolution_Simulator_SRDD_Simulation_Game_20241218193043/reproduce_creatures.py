def reproduce_creatures(self):
        offspring = []
        for creature in self.creatures:
            if random.random() < creature.reproduction_rate:
                offspring.append(Creature(creature.health, creature.speed, creature.reproduction_rate, creature.camouflage, creature.vision))
        self.creatures.extend(offspring)