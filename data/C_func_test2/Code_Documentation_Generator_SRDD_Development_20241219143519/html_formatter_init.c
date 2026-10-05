HTMLFormatter* html_formatter_init(CodeParser *parser) {
    HTMLFormatter *formatter = (HTMLFormatter *)malloc(sizeof(HTMLFormatter));
    formatter->parser = parser;
    return formatter;
}