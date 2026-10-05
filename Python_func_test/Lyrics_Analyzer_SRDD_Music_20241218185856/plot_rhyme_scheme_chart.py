def plot_rhyme_scheme_chart(rhyme_data):
    # Visualizes the rhyme scheme
    labels = list(rhyme_data.keys())
    values = list(rhyme_data.values())
    plt.bar(labels, values, color='skyblue')
    plt.xlabel('Line Number')
    plt.ylabel('Rhyme Scheme')
    plt.title('Rhyme Scheme Analysis')
    plt.xticks(rotation=45)
    plt.show()