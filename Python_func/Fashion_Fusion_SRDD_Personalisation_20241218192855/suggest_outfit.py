def suggest_outfit(self):
        items = self.wardrobe_manager.list_items()
        return self.analyze_style(items)