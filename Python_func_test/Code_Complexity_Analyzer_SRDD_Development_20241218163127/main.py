def main():
    code_snippet = """
    def example_function(x):
        if x > 0:
            for i in range(x):
                print(i)
        else:
            while x < 0:
                x += 1
                print(x)
    """
    analyzer = CodeAnalyzer(code_snippet)
    complexity_metrics = analyzer.analyze()
    visualizer = ComplexityVisualizer(complexity_metrics)
    visualizer.visualize_metrics()
    advisor = RefactoringAdvisor(complexity_metrics)
    advisor.suggest_refactoring()