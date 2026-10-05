void DataFormatter::applyFormattingRules() {
    transformer.changeDataType(data, 0, "int");
    transformer.rearrangeColumns(data, {1, 0, 2});
    transformer.removeDuplicates(data);
    transformer.mergeCells(data, 0, 1);
}