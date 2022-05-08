#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_LEN 80
#define MAX_PATH 80


int main(int argc, char* argv[]) {
    int ins_num = 0;
    int path_count = 0;
    int counter = 0;
    unsigned char flag = 0;
    int path_counter=0;
    int uncert_counter = 0;
    int cyc_count_str=0;
    int cyc_count_pos=0;
    int num_depth = 1;
    int depth = 3;
    char raw_path[MAX_PATH];
    
    char uncert[MAX_PATH]={'\0'};
    char string_mass[MAX_LEN][20]= {'\0'};
    char c;
    while ((c = getchar()) != '\n') {
        int detector = (int)c;
        if (isspace(c) == 0) {
            if (flag == 0) {
                if (detector >= 0) {
                    if (detector <= 128) {
                        path_count++;
                        raw_path[path_counter++] = c;
                    }
                }
            }
            else {
                uncert[uncert_counter++] = c;
            }
            
        }
        else {
            flag = 1;
        }
    }
    depth = atoi(uncert);
    //printf("SPECIAL %d", special);
    /*for (int t = strlen(uncert); t >= 0; t--) {
        ins_num = (int)uncert[t] - 48;
        printf("INS NUM %d \n", ins_num);
        depth = depth + (ins_num * num_depth);
        num_depth *= 10;
        printf("DEPTH %d", depth);
    }
    */
    //scanf("%s %d", &raw_path, &depth);
   // depth = depth - 48;
    printf("PATH_COUNT %d raw_path: %s DEPTH %d \n",path_count, raw_path, depth);
    char* real_path;
    //printf("PRT %d", path_count * sizeof(char));
    real_path = (char*)calloc(path_count+1,sizeof(char));
    for (int e = 0; e < path_count; e++) {
        *(real_path+e) = raw_path[e];

    }
    //printf("REAL PATH %s", real_path);
    FILE* file1 = fopen(real_path, "r");
    if (!file1)
        exit(EXIT_FAILURE);
    c = fgetc(file1);
    while (c != EOF) {
        int detector = (int)c;
        if (isspace(c) == 0) {
            if (detector >= 0) {
                if (detector <= 128) {
                    string_mass[cyc_count_str][cyc_count_pos] = c;
                    cyc_count_pos++;

                }
            }
        }
        if (c == '\n') {
            counter++;
            printf("N counter %d \n", counter);
            cyc_count_str++;
            cyc_count_pos = 0;
        }
        c = fgetc(file1);
    }
    for (int i = 0; i <= cyc_count_str; i++) {
        for (int j = 0; j < 20; j++) {
            /*if (isspace(string_mass[i][j]) == 0) {
                printf("%c", string_mass[i][j]);
            }
            */
            printf("%c", string_mass[i][j]);
        }
        printf("\n");
    }
    cyc_count_str++;//приводим к реальному числу для корректной печати
    printf("REAL MASS\n");
    for (int k = cyc_count_str - depth; k < cyc_count_str; k++) {
        for (int m = 0; m < 20; m++) {
            /*if (isspace(string_mass[i][j]) == 0) {
                printf("%c", string_mass[i][j]);
            }
            */
            printf("%c", string_mass[k][m]);
        }
        printf("\n");

    }
    counter++;
    fclose(file1);

    return 0;
    free(real_path);
}
