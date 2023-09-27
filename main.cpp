#include "pico/stdlib.h"
#include <cstdio>
#include <iterator>
#include <sstream>

#include "drivers/dv_display/dv_display.hpp"
#include "libraries/pico_graphics/pico_graphics_dv.hpp"

#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480

using namespace pimoroni;

DVDisplay display;
PicoGraphics_PenDV_RGB555 graphics(FRAME_WIDTH, FRAME_HEIGHT, display);

Pen BLACK = graphics.create_pen(0, 0, 0);
Pen WHITE = graphics.create_pen(255, 255, 255);

int main() {
    stdio_init_all();
    printf("Hello World\n");

    printf("Init Video...\n");
    display.preinit();
    display.init(FRAME_WIDTH, FRAME_HEIGHT, DVDisplay::MODE_RGB555);
    printf("Done!\n");

    graphics.set_font("bitmap8");

    while(true) {
        graphics.set_pen(BLACK);
        graphics.clear();
        graphics.set_pen(WHITE);
        graphics.text("Hello PicoVision Boilerplate!", Point(0, 0), FRAME_WIDTH);
        display.flip();
    }
}