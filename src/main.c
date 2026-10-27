#include "dropper.h"

void entry_point(void) {
    dropper_main();
    RtlExitUserProcess(0);
    __debugbreak(); // should not reach
}

int main(int argc, char** argv) {
    entry_point();
    return 0;
}
