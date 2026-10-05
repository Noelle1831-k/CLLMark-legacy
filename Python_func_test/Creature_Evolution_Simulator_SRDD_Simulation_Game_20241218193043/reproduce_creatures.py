def reproduce_creatures(self):
        offspring = list()
        for creature in self.creatures:
            if creature.reproduction_rate > random.random():
                offspring.append(Creature(creature.health, creature.speed, creature.reproduction_rate, creature.camouflage, creature.vision))
        self.creatures.extend(offspring)