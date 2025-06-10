#include <llvm-c/Core.h>
#include <llvm-c/Target.h>
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

typedef struct {
    LLVMBuilderRef builder;
    LLVMModuleRef module;
    LLVMValueRef garden_wait_func;
    LLVMValueRef garden_plant_func;
    LLVMValueRef garden_zone_decl_func;
    LLVMValueRef garden_water_func;
    LLVMValueRef garden_harvest_func;
    LLVMValueRef garden_fertilize_func;
    LLVMValueRef garden_prune_func;
    LLVMValueRef get_weather_temperature_func;
    LLVMValueRef get_soil_moisture_func;
    LLVMValueRef get_sensor_value_func;
} CodeGenContext;

void codegen_node(CodeGenContext* context, AST_Node* node);
LLVMValueRef codegen_expr(CodeGenContext* context, AST_Node* node);

void codegen(AST_Node* root, LLVMModuleRef module, LLVMBuilderRef builder) {
    if (root == NULL) {
        printf("AST está vazia, nada a gerar.\n");
        LLVMTypeRef main_func_type = LLVMFunctionType(LLVMInt32Type(), NULL, 0, 0);
        LLVMValueRef main_func = LLVMAddFunction(module, "main", main_func_type);
        LLVMBasicBlockRef entry_block = LLVMAppendBasicBlockInContext(LLVMGetGlobalContext(), main_func, "entry");
        LLVMPositionBuilderAtEnd(builder, entry_block);
        LLVMBuildRet(builder, LLVMConstInt(LLVMInt32Type(), 0, 0));
        return;
    }

    CodeGenContext context;
    context.builder = builder;
    context.module = module;

    LLVMTypeRef main_func_type = LLVMFunctionType(LLVMInt32Type(), NULL, 0, 0);
    LLVMValueRef main_func = LLVMAddFunction(module, "main", main_func_type);
    LLVMBasicBlockRef entry_block = LLVMAppendBasicBlockInContext(LLVMGetGlobalContext(), main_func, "entry");
    LLVMPositionBuilderAtEnd(builder, entry_block);

    LLVMTypeRef i8_ptr_type = LLVMPointerType(LLVMInt8Type(), 0);
    LLVMTypeRef i32_type = LLVMInt32Type();

    context.garden_wait_func = LLVMAddFunction(module, "garden_wait", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i32_type}, 1, 0));
    context.garden_plant_func = LLVMAddFunction(module, "garden_plant", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i8_ptr_type, i32_type, i32_type, i8_ptr_type}, 4, 0));
    context.garden_zone_decl_func = LLVMAddFunction(module, "garden_zone_decl", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i8_ptr_type, i32_type, i32_type, i32_type, i32_type}, 5, 0));
    context.garden_water_func = LLVMAddFunction(module, "garden_water", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i32_type, i32_type, i32_type}, 3, 0));
    context.garden_harvest_func = LLVMAddFunction(module, "garden_harvest", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i8_ptr_type, i8_ptr_type}, 2, 0));
    context.garden_fertilize_func = LLVMAddFunction(module, "garden_fertilize", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i8_ptr_type, i32_type, i32_type, i32_type}, 4, 0));
    context.garden_prune_func = LLVMAddFunction(module, "garden_prune", LLVMFunctionType(LLVMVoidType(), (LLVMTypeRef[]){i8_ptr_type, i32_type, i32_type}, 3, 0));
    context.get_weather_temperature_func = LLVMAddFunction(module, "get_weather_temperature", LLVMFunctionType(i32_type, NULL, 0, 0));
    context.get_soil_moisture_func = LLVMAddFunction(module, "get_soil_moisture", LLVMFunctionType(i32_type, (LLVMTypeRef[]){i32_type, i32_type}, 2, 0));
    context.get_sensor_value_func = LLVMAddFunction(module, "get_sensor_value", LLVMFunctionType(i32_type, (LLVMTypeRef[]){i8_ptr_type, i32_type, i32_type}, 3, 0));
    
    codegen_node(&context, root);
    LLVMBuildRet(builder, LLVMConstInt(i32_type, 0, 0));
}

void codegen_node(CodeGenContext* context, AST_Node* node) {
    if (node == NULL) return;

    switch (node->type) {
        case NODE_TYPE_SEQUENCE: {
            AST_Sequence_Node* seq_node = (AST_Sequence_Node*)node;
            codegen_node(context, seq_node->left);
            codegen_node(context, seq_node->right);
            break;
        }
        case NODE_TYPE_IF: {
            AST_If_Node* if_node = (AST_If_Node*)node;
            printf("Gerando código para: IF\n");
            LLVMValueRef condition_val = codegen_expr(context, if_node->condition);
            LLVMValueRef main_func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(context->builder));
            LLVMContextRef llvm_context = LLVMGetModuleContext(context->module);
            LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(llvm_context, main_func, "then");
            LLVMBasicBlockRef else_block = LLVMCreateBasicBlockInContext(llvm_context, "else");
            LLVMBasicBlockRef merge_block = LLVMCreateBasicBlockInContext(llvm_context, "if_cont");
            if (if_node->else_block) {
                LLVMBuildCondBr(context->builder, condition_val, then_block, else_block);
            } else {
                LLVMBuildCondBr(context->builder, condition_val, then_block, merge_block);
            }
            LLVMPositionBuilderAtEnd(context->builder, then_block);
            codegen_node(context, if_node->then_block);
            LLVMBuildBr(context->builder, merge_block);
            if (if_node->else_block) {
                LLVMAppendExistingBasicBlock(main_func, else_block);
                LLVMPositionBuilderAtEnd(context->builder, else_block);
                codegen_node(context, if_node->else_block);
                LLVMBuildBr(context->builder, merge_block);
            }
            LLVMAppendExistingBasicBlock(main_func, merge_block);
            LLVMPositionBuilderAtEnd(context->builder, merge_block);
            break;
        }
        case NODE_TYPE_LOOP: {
            AST_Loop_Node* loop_node = (AST_Loop_Node*)node;
            printf("Gerando código para: LOOP %d vezes\n", loop_node->times);
            LLVMValueRef main_func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(context->builder));
            LLVMContextRef llvm_context = LLVMGetModuleContext(context->module);
            LLVMValueRef counter_ptr = LLVMBuildAlloca(context->builder, LLVMInt32Type(), "loop_counter");
            LLVMBuildStore(context->builder, LLVMConstInt(LLVMInt32Type(), 0, 0), counter_ptr);
            LLVMBasicBlockRef loop_cond_block = LLVMAppendBasicBlockInContext(llvm_context, main_func, "loop_cond");
            LLVMBasicBlockRef loop_body_block = LLVMAppendBasicBlockInContext(llvm_context, main_func, "loop_body");
            LLVMBasicBlockRef loop_inc_block = LLVMAppendBasicBlockInContext(llvm_context, main_func, "loop_inc");
            LLVMBasicBlockRef loop_exit_block = LLVMAppendBasicBlockInContext(llvm_context, main_func, "loop_exit");
            LLVMBuildBr(context->builder, loop_cond_block);
            LLVMPositionBuilderAtEnd(context->builder, loop_cond_block);
            LLVMValueRef current_count = LLVMBuildLoad2(context->builder, LLVMInt32Type(), counter_ptr, "load_count");
            LLVMValueRef loop_limit = LLVMConstInt(LLVMInt32Type(), loop_node->times, 0);
            LLVMValueRef cmp = LLVMBuildICmp(context->builder, LLVMIntSLT, current_count, loop_limit, "loop_cmp");
            LLVMBuildCondBr(context->builder, cmp, loop_body_block, loop_exit_block);
            LLVMPositionBuilderAtEnd(context->builder, loop_body_block);
            codegen_node(context, loop_node->body);
            LLVMBuildBr(context->builder, loop_inc_block);
            LLVMPositionBuilderAtEnd(context->builder, loop_inc_block);
            LLVMValueRef old_count = LLVMBuildLoad2(context->builder, LLVMInt32Type(), counter_ptr, "load_old_count");
            LLVMValueRef new_count = LLVMBuildAdd(context->builder, old_count, LLVMConstInt(LLVMInt32Type(), 1, 0), "add_count");
            LLVMBuildStore(context->builder, new_count, counter_ptr);
            LLVMBuildBr(context->builder, loop_cond_block);
            LLVMPositionBuilderAtEnd(context->builder, loop_exit_block);
            break;
        }

        case NODE_TYPE_ZONE_DECL: {
            AST_Zone_Decl_Node* decl_node = (AST_Zone_Decl_Node*)node;
            printf("Gerando código para: ZONE %s\n", decl_node->name);
            LLVMValueRef name_str = LLVMBuildGlobalStringPtr(context->builder, decl_node->name, "zone_name");
            LLVMValueRef x1 = LLVMConstInt(LLVMInt32Type(), decl_node->p1.x, 0);
            LLVMValueRef y1 = LLVMConstInt(LLVMInt32Type(), decl_node->p1.y, 0);
            LLVMValueRef x2 = LLVMConstInt(LLVMInt32Type(), decl_node->p2.x, 0);
            LLVMValueRef y2 = LLVMConstInt(LLVMInt32Type(), decl_node->p2.y, 0);
            LLVMValueRef args[] = { name_str, x1, y1, x2, y2 };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_zone_decl_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_zone_decl_func, args, 5, "");
            break;
        }
        case NODE_TYPE_PLANT: {
            AST_Plant_Node* plant_node = (AST_Plant_Node*)node;
            printf("Gerando código para: PLANT %s\n", plant_node->plant_type);
            LLVMValueRef plant_type_str = LLVMBuildGlobalStringPtr(context->builder, plant_node->plant_type, "plant_type_str");
            LLVMValueRef x = LLVMConstInt(LLVMInt32Type(), plant_node->pos.x, 0);
            LLVMValueRef y = LLVMConstInt(LLVMInt32Type(), plant_node->pos.y, 0);
            LLVMValueRef zone_name_str;
            if (plant_node->zone_name) {
                zone_name_str = LLVMBuildGlobalStringPtr(context->builder, plant_node->zone_name, "zone_name_str");
            } else {
                zone_name_str = LLVMConstNull(LLVMPointerType(LLVMInt8Type(), 0));
            }
            LLVMValueRef args[] = { plant_type_str, x, y, zone_name_str };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_plant_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_plant_func, args, 4, "");
            break;
        }
        case NODE_TYPE_WATER: {
            AST_Water_Node* water_node = (AST_Water_Node*)node;
            printf("Gerando código para: WATER\n");
            int secs = water_node->dur.val;
            if (water_node->dur.unit == 'm') secs *= 60; else if (water_node->dur.unit == 'h') secs *= 3600;
            LLVMValueRef x = LLVMConstInt(LLVMInt32Type(), water_node->pos.x, 0);
            LLVMValueRef y = LLVMConstInt(LLVMInt32Type(), water_node->pos.y, 0);
            LLVMValueRef duration = LLVMConstInt(LLVMInt32Type(), secs, 0);
            LLVMValueRef args[] = { x, y, duration };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_water_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_water_func, args, 3, "");
            break;
        }
        case NODE_TYPE_HARVEST: {
            AST_Harvest_Node* harvest_node = (AST_Harvest_Node*)node;
            printf("Gerando código para: HARVEST %s\n", harvest_node->plant_type);
            LLVMValueRef plant_type_str = LLVMBuildGlobalStringPtr(context->builder, harvest_node->plant_type, "plant_type_str");
            LLVMValueRef zone_name_str;
            if (harvest_node->zone_name) {
                zone_name_str = LLVMBuildGlobalStringPtr(context->builder, harvest_node->zone_name, "zone_name_str");
            } else {
                zone_name_str = LLVMConstNull(LLVMPointerType(LLVMInt8Type(), 0));
            }
            LLVMValueRef args[] = { plant_type_str, zone_name_str };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_harvest_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_harvest_func, args, 2, "");
            break;
        }
        case NODE_TYPE_FERTILIZE: {
            AST_Fertilize_Node* fert_node = (AST_Fertilize_Node*)node;
            printf("Gerando código para: FERTILIZE\n");
            int secs = fert_node->dur.val;
            if (fert_node->dur.unit == 'm') secs *= 60; else if (fert_node->dur.unit == 'h') secs *= 3600;
            LLVMValueRef type_str = LLVMBuildGlobalStringPtr(context->builder, fert_node->fertilizer_type, "fert_type_str");
            LLVMValueRef x = LLVMConstInt(LLVMInt32Type(), fert_node->pos.x, 0);
            LLVMValueRef y = LLVMConstInt(LLVMInt32Type(), fert_node->pos.y, 0);
            LLVMValueRef duration = LLVMConstInt(LLVMInt32Type(), secs, 0);
            LLVMValueRef args[] = { type_str, x, y, duration };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_fertilize_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_fertilize_func, args, 4, "");
            break;
        }
        case NODE_TYPE_PRUNE: {
            AST_Prune_Node* prune_node = (AST_Prune_Node*)node;
            printf("Gerando código para: PRUNE %s\n", prune_node->plant_type);
            LLVMValueRef type_str = LLVMBuildGlobalStringPtr(context->builder, prune_node->plant_type, "prune_type_str");
            LLVMValueRef x = LLVMConstInt(LLVMInt32Type(), prune_node->pos.x, 0);
            LLVMValueRef y = LLVMConstInt(LLVMInt32Type(), prune_node->pos.y, 0);
            LLVMValueRef args[] = { type_str, x, y };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_prune_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_prune_func, args, 3, "");
            break;
        }
        case NODE_TYPE_WAIT: {
            AST_Wait_Node* wait_node = (AST_Wait_Node*)node;
            printf("Gerando código para: WAIT %d segundos\n", wait_node->seconds);
            LLVMValueRef args[] = { LLVMConstInt(LLVMInt32Type(), wait_node->seconds, 0) };
            LLVMTypeRef funcType = LLVMGlobalGetValueType(context->garden_wait_func);
            LLVMBuildCall2(context->builder, funcType, context->garden_wait_func, args, 1, "");
            break;
        }
        default:
            printf("Aviso: Geração de código para o nó de statement %d ainda não implementada.\n", node->type);
            break;
    }
}

LLVMValueRef codegen_expr(CodeGenContext* context, AST_Node* node) {
    if (node == NULL) return NULL;
    switch (node->type) {
        case NODE_TYPE_WEATHER_COND: {
            AST_Weather_Cond_Node* cond_node = (AST_Weather_Cond_Node*)node;
            printf("Gerando expressão para: WEATHER.%s\n", cond_node->field);
            LLVMValueRef sensor_val = LLVMBuildCall2(context->builder, LLVMGlobalGetValueType(context->get_weather_temperature_func), context->get_weather_temperature_func, NULL, 0, "temp_val");
            LLVMValueRef const_val = LLVMConstInt(LLVMInt32Type(), cond_node->value.value, 0);
            LLVMIntPredicate op;
            switch(cond_node->op) { case OP_GT: op = LLVMIntSGT; break; case OP_LT: op = LLVMIntSLT; break; case OP_EQ: op = LLVMIntEQ;  break; case OP_GE: op = LLVMIntSGE; break; case OP_LE: op = LLVMIntSLE; break; }
            return LLVMBuildICmp(context->builder, op, sensor_val, const_val, "weather_cmp");
        }
        case NODE_TYPE_SOIL_COND: {
            AST_Soil_Cond_Node* cond_node = (AST_Soil_Cond_Node*)node;
            printf("Gerando expressão para: SOIL_MOISTURE\n");
            LLVMValueRef x = LLVMConstInt(LLVMInt32Type(), cond_node->pos.x, 0);
            LLVMValueRef y = LLVMConstInt(LLVMInt32Type(), cond_node->pos.y, 0);
            LLVMValueRef args[] = {x, y};
            LLVMValueRef sensor_val = LLVMBuildCall2(context->builder, LLVMGlobalGetValueType(context->get_soil_moisture_func), context->get_soil_moisture_func, args, 2, "soil_val");
            LLVMValueRef const_val = LLVMConstInt(LLVMInt32Type(), cond_node->value.value, 0);
            LLVMIntPredicate op;
            switch(cond_node->op) { case OP_GT: op = LLVMIntSGT; break; case OP_LT: op = LLVMIntSLT; break; case OP_EQ: op = LLVMIntEQ;  break; case OP_GE: op = LLVMIntSGE; break; case OP_LE: op = LLVMIntSLE; break; }
            return LLVMBuildICmp(context->builder, op, sensor_val, const_val, "soil_cmp");
        }
        case NODE_TYPE_SENSOR_COND: {
            AST_Sensor_Cond_Node* cond_node = (AST_Sensor_Cond_Node*)node;
            printf("Gerando expressão para: SENSOR %s\n", cond_node->sensor_type);
            LLVMValueRef type_str = LLVMBuildGlobalStringPtr(context->builder, cond_node->sensor_type, "sensor_type_str");
            LLVMValueRef x = LLVMConstInt(LLVMInt32Type(), cond_node->pos.x, 0);
            LLVMValueRef y = LLVMConstInt(LLVMInt32Type(), cond_node->pos.y, 0);
            LLVMValueRef args[] = {type_str, x, y};
            LLVMValueRef sensor_val = LLVMBuildCall2(context->builder, LLVMGlobalGetValueType(context->get_sensor_value_func), context->get_sensor_value_func, args, 3, "sensor_val");
            LLVMValueRef const_val = LLVMConstInt(LLVMInt32Type(), cond_node->value.value, 0);
            LLVMIntPredicate op;
            switch(cond_node->op) { case OP_GT: op = LLVMIntSGT; break; case OP_LT: op = LLVMIntSLT; break; case OP_EQ: op = LLVMIntEQ;  break; case OP_GE: op = LLVMIntSGE; break; case OP_LE: op = LLVMIntSLE; break; }
            return LLVMBuildICmp(context->builder, op, sensor_val, const_val, "sensor_cmp");
        }
        default:
            fprintf(stderr, "Erro: Geração de código para o nó de expressão %d não implementada.\n", node->type);
            return NULL;
    }
}