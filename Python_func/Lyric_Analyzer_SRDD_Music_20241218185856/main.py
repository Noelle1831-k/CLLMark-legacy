def main():
    lyrics = load_lyrics()
    analyzer = LyricAnalyzer(lyrics)
    analysis_results = analyzer.analyze_lyrics()
    visualizer = Visualizer(analysis_results)
    visualizer.create_charts()
    visualizer.display_visuals()