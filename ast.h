#ifndef AST_H
#define AST_H

#include "types.h"

typedef enum {
    NODE_TYPE_SEQUENCE, NODE_TYPE_ZONE_DECL, NODE_TYPE_PLANT, NODE_TYPE_WATER, NODE_TYPE_HARVEST, NODE_TYPE_FERTILIZE,
    NODE_TYPE_PRUNE, NODE_TYPE_WAIT, NODE_TYPE_LOOP, NODE_TYPE_IF, NODE_TYPE_SOIL_COND, NODE_TYPE_WEATHER_COND, NODE_TYPE_SENSOR_COND
} AST_NodeType;
typedef enum { OP_GT = 1, OP_LT, OP_GE, OP_LE, OP_EQ } CompOp;
typedef struct AST_Node { AST_NodeType type; } AST_Node;
typedef struct { AST_Node base; AST_Node *left; AST_Node *right; } AST_Sequence_Node;
typedef struct { AST_Node base; char* name; struct coord p1; struct coord p2; } AST_Zone_Decl_Node;
typedef struct { AST_Node base; int seconds; } AST_Wait_Node;
typedef struct { AST_Node base; char* plant_type; struct coord pos; char* zone_name; } AST_Plant_Node;
typedef struct { AST_Node base; struct coord pos; struct duration dur; AST_Node* condition; } AST_Water_Node;
typedef struct { AST_Node base; char* plant_type; char* zone_name; } AST_Harvest_Node;
typedef struct { AST_Node base; char* fertilizer_type; struct coord pos; struct duration dur; } AST_Fertilize_Node;
typedef struct { AST_Node base; char* plant_type; struct coord pos; } AST_Prune_Node;
typedef struct { AST_Node base; AST_Node* condition; AST_Node* then_block; AST_Node* else_block; } AST_If_Node;
typedef struct { AST_Node base; int times; AST_Node* body; } AST_Loop_Node;
typedef struct { AST_Node base; char* field; CompOp op; struct value_type value; } AST_Weather_Cond_Node;
typedef struct { AST_Node base; CompOp op; struct value_type value; struct coord pos; } AST_Soil_Cond_Node;
typedef struct { AST_Node base; char* sensor_type; CompOp op; struct value_type value; struct coord pos; } AST_Sensor_Cond_Node;
AST_Node* ast_create_sequence_node(AST_Node* left, AST_Node* right);
AST_Node* ast_create_zone_decl_node(char* name, struct coord p1, struct coord p2);
AST_Node* ast_create_plant_node(char* plant_type, struct coord pos, char* zone_name);
AST_Node* ast_create_water_node(struct coord pos, struct duration dur, AST_Node* condition);
AST_Node* ast_create_harvest_node(char* plant_type, char* zone_name);
AST_Node* ast_create_fertilize_node(char* fertilizer_type, struct coord pos, struct duration dur);
AST_Node* ast_create_prune_node(char* plant_type, struct coord pos);
AST_Node* ast_create_wait_node(int value, char unit);
AST_Node* ast_create_loop_node(int times, AST_Node* body);
AST_Node* ast_create_if_node(AST_Node* condition, AST_Node* then_block, AST_Node* else_block);
AST_Node* ast_create_weather_cond_node(char* field, int op, struct value_type value);
AST_Node* ast_create_soil_cond_node(int op, struct value_type value, struct coord pos);
AST_Node* ast_create_sensor_cond_node(char* sensor_type, int op, struct value_type value, struct coord pos);

#endif