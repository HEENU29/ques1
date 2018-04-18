#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct processStruct {
    int pNum;
    int arTime;
    int cpuBur;
    int prio;
    int waitTim;
};

struct processStruct structs[MAX];

int main(int argc, char** args)
{ 
    FILE *fil;
    char typeOf[4];
    int numPro, i;
    if ((fil = fopen("myfile.txt", "rt")) == NULL)
        exit(1);
    if(fscanf(fil, "%4s", typeOf) != 1)
        exit(1);
    if(fscanf(fil, "%d", &numPro) != 1)
        exit(1);
    if(numPro > MAX)
        exit(1);
    for(i=0; i<numPro; i++) {
        if(fscanf(fil, "%d%d%d%d", &structs[i].pNum, &structs[i].arTime,
                                   &structs[i].cpuBur, &structs[i].prio) != 4)
            exit(1);
    }
    fclose(fil);

    // test the result
    printf("Type: %s\n", typeOf);
    printf("Num: %d\n", numPro);
    for(i=0; i<numPro; i++) {
        printf("%d %d %d %d\n", structs[i].pNum, structs[i].arTime,
                                structs[i].cpuBur, structs[i].prio);
    }
    return 0;
}
