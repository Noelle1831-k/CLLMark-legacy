ValidationRules* createValidationRules() {
    ValidationRules *rules = (ValidationRules *)malloc(sizeof(ValidationRules));
    if (!rules) {
        fprintf(stderr, "Memory allocation failed for ValidationRules.\n");
        return NULL;
    }
    rules->typeValidation = 1;
    rules->rangeValidation = 1;
    rules->uniquenessValidation = 1;
    rules->minRange = 0;
    rules->maxRange = 100;
    return rules;
}