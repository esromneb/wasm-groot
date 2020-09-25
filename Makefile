
.PHONY: all clean wasm


# warning and error flags
CLANG_WARN_FLAGS = \
-Wall -Wextra \
-Wno-ignored-qualifiers \
-Wundef \
-Werror=return-type \
-Wshadow \
# -Wconversion

CLANG_OTHER_FLAGS = \
-fPIC


FNAME=main

all: wasm

wasm: out out/$(FNAME).wasm

out:
	mkdir -p out

out/side.o: csrc/side.cpp
	em++ csrc/side.cpp -c -o out/side.o $(CLANG_WARN_FLAGS) $(CLANG_OTHER_FLAGS)


out/main.o: csrc/main.cpp
	em++ csrc/main.cpp -c -o out/main.o $(CLANG_WARN_FLAGS) $(CLANG_OTHER_FLAGS)

# out/$(FNAME).wasm
# lib/Groot/build/libbehavior_tree_editor.so
out/$(FNAME).wasm: out out/main.o out/side.o
	emcc \
	out/side.o \
	out/main.o \
	lib/Groot/build/lib/libbehaviortree_cpp_v3.so \
	lib/Groot/build/lib/libQtNodeEditor.a \
	lib/Groot/build/libGroot.a \
	-s WASM_OBJECT_FILES=0 \
	-s MAIN_MODULE=1 \
	-o out/$(FNAME).html \
	-s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "addOnPostRun", "addFunction", "setValue", "getValue"]' \
	$(CLANG_WARN_FLAGS) $(CLANG_OTHER_FLAGS)

# 	'-std=c++2a' \



clean:
	rm -rf out
