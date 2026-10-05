def generate_visuals(processed_data):
    categorized_data = processed_data['categorized_data']
    labels = categorized_data.keys()
    sizes = categorized_data.values()
    plt.figure(figsize=(10, 6))
    plt.pie(sizes, labels=labels, autopct='%1.1f%%')
    plt.title('Budget Breakdown')
    plt.show()