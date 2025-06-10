#include <stdio.h>
#include <stdlib.h>
#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include "ast.h"

extern int yyparse(struct AST_Node** root);
void codegen(struct AST_Node* root, LLVMModuleRef module, LLVMBuilderRef builder);
extern FILE *yyin;

extern void garden_zone_decl(char* name, int x1, int y1, int x2, int y2);
extern void garden_plant(char* plant_type, int x, int y, char* zone_name);
extern void garden_water(int x, int y, int duration_s);
extern void garden_harvest(char* plant_type, char* zone_name);
extern void garden_fertilize(char* fertilizer_type, int x, int y, int duration_s);
extern void garden_prune(char* plant_type, int x, int y);
extern void garden_wait(int seconds);
extern int get_weather_temperature();
extern int get_soil_moisture(int x, int y);
extern int get_sensor_value(char* sensor_type, int x, int y);


int main(int argc, char **argv) {
    if (argc < 2) {
      fprintf(stderr, "Uso: %s <arquivo.garden>\n", argv[0]);
      return 1;
    }
    yyin = fopen(argv[1], "r");

    struct AST_Node* ast_root = NULL;
    yyparse(&ast_root);

    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMInitializeNativeAsmParser();

    LLVMContextRef context = LLVMContextCreate();
    LLVMModuleRef module = LLVMModuleCreateWithNameInContext("gardengo", context);
    LLVMBuilderRef builder = LLVMCreateBuilderInContext(context);

    codegen(ast_root, module, builder);
    
    printf("\n--- LLVM IR Gerado ---\n");
    LLVMDumpModule(module);
    printf("----------------------\n\n");

    char *error = NULL;
    LLVMExecutionEngineRef engine;
    
    LLVMLinkInMCJIT();
    
    // --- REGISTRO DE TODOS OS SÍMBOLOS PARA O JIT ---
    LLVMAddSymbol("garden_zone_decl", &garden_zone_decl);
    LLVMAddSymbol("garden_plant", &garden_plant);
    LLVMAddSymbol("garden_water", &garden_water);
    LLVMAddSymbol("garden_harvest", &garden_harvest);
    LLVMAddSymbol("garden_fertilize", &garden_fertilize);
    LLVMAddSymbol("garden_prune", &garden_prune);
    LLVMAddSymbol("garden_wait", &garden_wait);
    LLVMAddSymbol("get_weather_temperature", &get_weather_temperature);
    LLVMAddSymbol("get_soil_moisture", &get_soil_moisture);
    LLVMAddSymbol("get_sensor_value", &get_sensor_value);

    if (LLVMCreateExecutionEngineForModule(&engine, module, &error) != 0) {
        fprintf(stderr, "Falha ao criar o motor de execução: %s\n", error);
        LLVMDisposeMessage(error);
        exit(1);
    }

    LLVMValueRef main_func = LLVMGetNamedFunction(module, "main");
    if (main_func == NULL) {
        fprintf(stderr, "Função 'main' não encontrada no código gerado.\n");
        exit(1);
    }
    
    printf("--- Executando o código com JIT ---\n");
    LLVMRunFunction(engine, main_func, 0, NULL);
    printf("--- Execução Concluída ---\n");

    LLVMDisposeBuilder(builder);
    LLVMDisposeExecutionEngine(engine);

    return 0;
}