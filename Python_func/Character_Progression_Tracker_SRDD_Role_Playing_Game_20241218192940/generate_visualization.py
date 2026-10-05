def generate_visualization(self, character):
        attributes = character.attributes
        levels = [character.level] * len(attributes)
        plt.figure(figsize=(10, 6))
        plt.bar(attributes, levels, color='skyblue')
        plt.title(f"{character.name}'s Attributes at Level {character.level}")
        plt.xlabel('Attributes')
        plt.ylabel('Level')
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()