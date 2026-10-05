def equip_item(self, item):
        self.equipment.append(item)
        item.equip(self)