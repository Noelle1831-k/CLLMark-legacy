void doc_generator_run(DocGenerator *doc_gen) {
    CodeParser *parser = code_parser_init(doc_gen->source_code_directory);
    code_parser_parse_code(parser);
    if (strcmp(doc_gen->output_format, "html") == 0) {
        HTMLFormatter *html_formatter = html_formatter_init(parser);
        char *html_content = html_formatter_format_html(html_formatter);
        write_file("documentation.html", html_content);
        free(html_content);
        html_formatter_free(html_formatter);
    } else if (strcmp(doc_gen->output_format, "pdf") == 0) {
        PDFFormatter *pdf_formatter = pdf_formatter_init(parser);
        char *pdf_content = pdf_formatter_format_pdf(pdf_formatter);
        write_file("documentation.pdf", pdf_content);
        free(pdf_content);
        pdf_formatter_free(pdf_formatter);
    }
    code_parser_free(parser);
}