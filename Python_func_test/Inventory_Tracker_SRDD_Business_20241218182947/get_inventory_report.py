def get_inventory_report(self):
        report = "Inventory Report:\n"
        for item in self.items.values():
            report += item.get_item_details() + "\n"
        return report