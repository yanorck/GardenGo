CC=gcc
CXX=g++

# Flags do LLVM
LLVM_CFLAGS := $(shell llvm-config --cflags)
LLVM_LDFLAGS := $(shell llvm-config --ldflags --system-libs --libs core analysis executionengine native)

# Nossos arquivos
C_SOURCES = main.c ast.c codegen.c garden_runtime.c
BISON_SOURCE = parser.y
FLEX_SOURCE = scanner.l

TARGET = gardengo_compiler

all: $(TARGET)

# Compila o parser e o scanner
parser.tab.c parser.tab.h: $(BISON_SOURCE)
	bison -d -Wcounterexamples -o parser.tab.c $(BISON_SOURCE)

lex.yy.c: $(FLEX_SOURCE) parser.tab.h
	flex -o lex.yy.c $(FLEX_SOURCE)

# Compila e linka tudo
$(TARGET): $(C_SOURCES) parser.tab.c lex.yy.c
	$(CC) -o $@ $^ $(LLVM_CFLAGS) $(LLVM_LDFLAGS) -Wno-implicit-function-declaration

clean:
	rm -f $(TARGET) *.o *.tab.c *.tab.h lex.yy.c