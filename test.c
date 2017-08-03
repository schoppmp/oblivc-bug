#include "obliv.oh"
#include "obliv.h"
#include <stdio.h>

#define myint int
#define feedOblivMyintArray feedOblivIntArray

void circuit(void *_arg) {
    size_t k = 101;
    myint *array = calloc(k, sizeof(myint));
    obliv myint *obliv_array = calloc(k, sizeof(obliv myint));
    feedOblivMyintArray(obliv_array, array, k, 2);
    free(array);
    free(obliv_array);
}

int main(int argc, char** argv) {
    int party = atoi(argv[1]);
    printf("sizeof(int) is %zd\n", sizeof(int));
    ProtocolDesc pd;
    if(party == 1) {
        protocolConnectTcp2P(&pd,"localhost", "23456");
    } else {
        protocolAcceptTcp2P(&pd, "23456");
    }
    setCurrentParty(&pd, party);
    execYaoProtocol(&pd, circuit, NULL);
    return 0;
}
