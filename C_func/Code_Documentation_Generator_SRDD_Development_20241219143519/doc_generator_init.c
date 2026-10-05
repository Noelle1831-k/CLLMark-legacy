DocGenerator* doc_generator_init(char *source_code_directory, char *output_format) {
    DocGenerator *doc_gen = (DocGenerator *)malloc(sizeof(DocGenerator));
    doc_gen->source_code_directory = strdup(source_code_directory);
    doc_gen->output_format = strdup(output_format);
    return doc_gen;
}