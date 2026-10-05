from tree_sitter import Language


libs = ['/tree-sitter/tree-sitter-cpp-0.21.0',"/tree-sitter/tree-sitter-cpp-0.21.0",'/tree-sitter/tree-sitter-cpp-0.21.0']
for lib in libs:
    arc = [lib]
    lang = lib.replace("tree-sitter-",'').replace('-0.21.0','')
    Language.build_library(
        # Store the library in the `build` directory
        f"1/{lang}-languages.so",
        arc
    )
