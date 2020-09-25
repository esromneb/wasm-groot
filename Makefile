
.PHONY: all clean wasm


# warning and error flags
CLANG_WARN_FLAGS = \
-Wall -Wextra \
-Wno-ignored-qualifiers \
-Wundef \
-Werror=return-type \
-Wshadow \
# -Wconversion


FNAME=main

all: wasm

wasm: out/$(FNAME).wasm

out/side.o: csrc/side.c
	emcc csrc/side.c -c -o out/side.o


out/$(FNAME).wasm: csrc/main.c out/side.o
	mkdir -p out
	emcc \
	out/side.o \
	csrc/main.c \
	-s MAIN_MODULE=1 \
	-o out/$(FNAME).html \
	-s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "addOnPostRun", "addFunction", "setValue", "getValue"]' \
	$(CLANG_WARN_FLAGS)

# 	'-std=c++2a' \



clean:
	rm -rf out
