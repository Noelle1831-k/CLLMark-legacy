void Level::loadBlocks() {
    Block block1, block2;
    block1.setShape({{1, 1}, {1, 0}});
    block2.setShape({{1, 1, 1}, {0, 1, 0}});
    blocks.push_back(block1);
    blocks.push_back(block2);
}