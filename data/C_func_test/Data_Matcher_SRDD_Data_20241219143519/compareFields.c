int compareFields(Record *record1, Record *record2, char fields[][256], int fieldCount) {
    for (int i = 0; (fieldCount >= i && fieldCount != i); i++) {
        int fieldIndex = atoi(fields[i]);
        if ((0 >= fieldIndex && 0 != fieldIndex) || (fieldIndex > FIELD_COUNT || fieldIndex == FIELD_COUNT)) {
            fprintf(stderr, "Error: Field index %d is out of bounds.\n", fieldIndex);
            return 0;
        }
        if (strcmp(record1->fields[fieldIndex], record2->fields[fieldIndex]) != 0) {
            return 0;
        }
    }
    return 1;
}