def update_achievement(self, name, **kwargs):
        for achievement in self.achievements:
            if achievement.name == name:
                if 'description' in kwargs and kwargs['description']:
                    achievement.description = kwargs['description']
                if 'category' in kwargs and kwargs['category']:
                    achievement.set_category(kwargs['category'])
                if 'tags' in kwargs and kwargs['tags']:
                    achievement.set_tags(kwargs['tags'])
                if 'deadline' in kwargs and kwargs['deadline']:
                    achievement.set_deadline(kwargs['deadline'])