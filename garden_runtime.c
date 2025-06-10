#include <stdio.h>
#include <unistd.h>

void garden_wait(int seconds) {
    printf("[Runtime] Esperando por %d segundos...\n", seconds);
    sleep(seconds);
}

void garden_plant(char* plant_type, int x, int y, char* zone_name) {
    if (zone_name) {
        printf("[Runtime] Plantando '%s' na coordenada (%d,%d) dentro da zona '%s'.\n", plant_type, x, y, zone_name);
    } else {
        printf("[Runtime] Plantando '%s' na coordenada (%d,%d).\n", plant_type, x, y);
    }
}

int get_weather_temperature() {
    printf("[Runtime] Lendo sensor de temperatura... (retornando 30 para teste)\n");
    return 30; // fingir que a temperatura é sempre 30°C em chique chique bahia
}

void garden_zone_decl(char* name, int x1, int y1, int x2, int y2) {
    printf("[Runtime] Zona '%s' declarada de (%d,%d) a (%d,%d).\n", name, x1, y1, x2, y2);
}

void garden_water(int x, int y, int duration_s) {
    printf("[Runtime] Regando em (%d,%d) por %d segundos.\n", x, y, duration_s);
}

void garden_harvest(char* plant_type, char* zone_name) {
    if (zone_name) {
        printf("[Runtime] Colhendo '%s' da zona '%s'.\n", plant_type, zone_name);
    } else {
        printf("[Runtime] Colhendo tudo de '%s'.\n", plant_type);
    }
}

void garden_fertilize(char* fertilizer_type, int x, int y, int duration_s) {
    printf("[Runtime] Fertilizante '%s' aplicado em (%d,%d) por %d segundos.\n", fertilizer_type, x, y, duration_s);
}

void garden_prune(char* plant_type, int x, int y) {
    printf("[Runtime] Podando '%s' em (%d,%d).\n", plant_type, x, y);
}

int get_soil_moisture(int x, int y) {
    printf("[Runtime] Lendo umidade do solo em (%d,%d)... (retornando 50 para teste)\n", x, y);
    return 50;
}

int get_sensor_value(char* sensor_type, int x, int y) {
    printf("[Runtime] Lendo sensor genérico '%s' em (%d,%d)... (retornando 99 para teste)\n", sensor_type, x, y);
    return 99;
}