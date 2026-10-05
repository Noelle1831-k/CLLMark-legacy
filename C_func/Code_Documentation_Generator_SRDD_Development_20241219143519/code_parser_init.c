CodeParser* code_parser_init(char *source_code_directory) {
    CodeParser *parser = (CodeParser *)malloc(sizeof(CodeParser));
    parser->source_code = read_file(source_code_directory);
    return parser;
}