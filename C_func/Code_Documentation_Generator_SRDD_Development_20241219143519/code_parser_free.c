void code_parser_free(CodeParser *parser) {
    free(parser->source_code);
    free(parser);
}