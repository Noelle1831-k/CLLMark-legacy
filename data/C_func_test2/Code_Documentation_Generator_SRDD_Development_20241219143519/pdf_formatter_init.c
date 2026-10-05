PDFFormatter* pdf_formatter_init(CodeParser *parser) {
    PDFFormatter *formatter = (PDFFormatter *)malloc(sizeof(PDFFormatter));
    formatter->parser = parser;
    return formatter;
}