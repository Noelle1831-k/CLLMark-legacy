def add_clip_to_category(self, clip, category_name):
        # Add a clip to a category
        if category_name in self.categories:
            self.categories[category_name].append(clip)
            print(f"Clip '{clip['name']}' added to category '{category_name}'.")