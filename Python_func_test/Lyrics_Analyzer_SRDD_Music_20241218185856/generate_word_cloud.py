def generate_word_cloud(frequency_data):
    # Creates a word cloud from word frequency data
    wordcloud = WordCloud(width=800, height=400, background_color='white').generate_from_frequencies(frequency_data)
    plt.figure(figsize=(10, 5))
    plt.imshow(wordcloud, interpolation='bilinear')
    plt.axis('off')
    plt.title("Word Cloud")
    plt.show()