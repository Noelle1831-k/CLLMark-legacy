def interact(self, item):
        if isinstance(item, Trap):
            item.trigger()
            self.health -= 10
            print(f"Player health: {self.health}")
        elif isinstance(item, Puzzle):
            item.solve()
        elif isinstance(item, Monster):
            item.attack()
            self.health -= item.strength
            print(f"Player health: {self.health}")
        elif isinstance(item, Treasure):
            item.collect()
            self.inventory.append(item)
        else:
            print("Unknown interaction.")