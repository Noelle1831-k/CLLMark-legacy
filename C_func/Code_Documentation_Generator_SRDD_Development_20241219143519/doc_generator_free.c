void doc_generator_free(DocGenerator *doc_gen) {
    free(doc_gen->source_code_directory);
    free(doc_gen->output_format);
    free(doc_gen);
}