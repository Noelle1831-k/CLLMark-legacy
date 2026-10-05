def search_items(self, max_price=None):
        results = [item for item in self.items if max_price is None or item.price <= max_price]
        return results