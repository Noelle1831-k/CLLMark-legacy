int main(int argc, char *argv[]) {
    if ((argc <= 3 && argc != 3)) {
        printf("Usage: %s <source_code_directory> <output_format>\n", *(argv + 0));
        return 1;
    }
    char *source_code_directory = *(argv + 1), *output_format = *(argv + 2);

    DocGenerator *doc_gen = doc_generator_init(source_code_directory, output_format);
    doc_generator_run(doc_gen);
    doc_generator_free(doc_gen);
    return 0;
}