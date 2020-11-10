#include "faasm/faasm.h"

#include <stdio.h>

#define STATE_KEY "printable"

int main(int argc, char* argv[])
{
    size_t stateSize = faasmReadStateSize(STATE_KEY);
    printf("State %s size: %lu\n", STATE_KEY, stateSize);

    auto stateBuffer = new char[stateSize];

    faasmReadState(STATE_KEY, BYTES(stateBuffer), stateSize);
    printf("Read state as: %s\n", stateBuffer);

    return 0;
}
