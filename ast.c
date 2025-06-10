#include <stdlib.h>
#include <string.h>
#include "ast.h"


AST_Node* ast_create_sequence_node(AST_Node* left, AST_Node* right) {
    if (left == NULL) {
        return right;
    }
    AST_Sequence_Node* node = malloc(sizeof(AST_Sequence_Node));
    node->base.type = NODE_TYPE_SEQUENCE;
    node->left = left;
    node->right = right;
    return (AST_Node*)node;
}

AST_Node* ast_create_wait_node(int value, char unit) {
    AST_Wait_Node* node = malloc(sizeof(AST_Wait_Node));
    node->base.type = NODE_TYPE_WAIT;
    int secs = value;
    if (unit == 'm') secs *= 60;
    else if (unit == 'h') secs *= 3600;
    node->seconds = secs;
    return (AST_Node*)node;
}

AST_Node* ast_create_zone_decl_node(char* name, struct coord p1, struct coord p2) {
    AST_Zone_Decl_Node* node = malloc(sizeof(AST_Zone_Decl_Node));
    node->base.type = NODE_TYPE_ZONE_DECL;
    node->name = strdup(name);
    node->p1 = p1;
    node->p2 = p2;
    free(name);
    return (AST_Node*)node;
}

AST_Node* ast_create_plant_node(char* plant_type, struct coord pos, char* zone_name) {
    AST_Plant_Node* node = malloc(sizeof(AST_Plant_Node));
    node->base.type = NODE_TYPE_PLANT;
    node->plant_type = strdup(plant_type);
    node->pos = pos;
    node->zone_name = (zone_name) ? strdup(zone_name) : NULL;
    free(plant_type);
    if(zone_name) free(zone_name);
    return (AST_Node*)node;
}

AST_Node* ast_create_water_node(struct coord pos, struct duration dur, AST_Node* condition) {
    AST_Water_Node* node = malloc(sizeof(AST_Water_Node));
    node->base.type = NODE_TYPE_WATER;
    node->pos = pos;
    node->dur = dur;
    node->condition = condition;
    return (AST_Node*)node;
}

AST_Node* ast_create_harvest_node(char* plant_type, char* zone_name) {
    AST_Harvest_Node* node = malloc(sizeof(AST_Harvest_Node));
    node->base.type = NODE_TYPE_HARVEST;
    node->plant_type = strdup(plant_type);
    node->zone_name = (zone_name) ? strdup(zone_name) : NULL;
    free(plant_type);
    if(zone_name) free(zone_name);
    return (AST_Node*)node;
}

AST_Node* ast_create_fertilize_node(char* fertilizer_type, struct coord pos, struct duration dur) {
    AST_Fertilize_Node* node = malloc(sizeof(AST_Fertilize_Node));
    node->base.type = NODE_TYPE_FERTILIZE;
    node->fertilizer_type = strdup(fertilizer_type);
    node->pos = pos;
    node->dur = dur;
    free(fertilizer_type);
    return (AST_Node*)node;
}

AST_Node* ast_create_prune_node(char* plant_type, struct coord pos) {
    AST_Prune_Node* node = malloc(sizeof(AST_Prune_Node));
    node->base.type = NODE_TYPE_PRUNE;
    node->plant_type = strdup(plant_type);
    node->pos = pos;
    free(plant_type);
    return (AST_Node*)node;
}

AST_Node* ast_create_loop_node(int times, AST_Node* body) {
    AST_Loop_Node* node = malloc(sizeof(AST_Loop_Node));
    node->base.type = NODE_TYPE_LOOP;
    node->times = times;
    node->body = body;
    return (AST_Node*)node;
}

AST_Node* ast_create_if_node(AST_Node* condition, AST_Node* then_block, AST_Node* else_block) {
    AST_If_Node* node = malloc(sizeof(AST_If_Node));
    node->base.type = NODE_TYPE_IF;
    node->condition = condition;
    node->then_block = then_block;
    node->else_block = else_block;
    return (AST_Node*)node;
}

AST_Node* ast_create_weather_cond_node(char* field, int op, struct value_type value) {
    AST_Weather_Cond_Node* node = malloc(sizeof(AST_Weather_Cond_Node));
    node->base.type = NODE_TYPE_WEATHER_COND;
    node->field = strdup(field);
    node->op = op;
    node->value = value;
    free(field);
    return (AST_Node*)node;
}

AST_Node* ast_create_soil_cond_node(int op, struct value_type value, struct coord pos) {
    AST_Soil_Cond_Node* node = malloc(sizeof(AST_Soil_Cond_Node));
    node->base.type = NODE_TYPE_SOIL_COND;
    node->op = op;
    node->value = value;
    node->pos = pos;
    return (AST_Node*)node;
}

AST_Node* ast_create_sensor_cond_node(char* sensor_type, int op, struct value_type value, struct coord pos) {
    AST_Sensor_Cond_Node* node = malloc(sizeof(AST_Sensor_Cond_Node));
    node->base.type = NODE_TYPE_SENSOR_COND;
    node->sensor_type = strdup(sensor_type);
    node->op = op;
    node->value = value;
    node->pos = pos;
    free(sensor_type);
    return (AST_Node*)node;
}