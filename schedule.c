#include <stdio.h>
#define COURSE_NUM 5
#define WEEKDAY 5
#define CLASS 6
struct Course{
    char name[20];
    int code;
};
void add_schedule(int schedule[CLASS][WEEKDAY],int weekday,int classNum,int courseCode){
    schedule[classNum-1][weekday-1] = courseCode;
}
int main(void){
    struct Course courses[COURSE_NUM];
    int schedule[CLASS][WEEKDAY]={0};
    for(int i=0;i<COURSE_NUM;i++){
        printf("輸入課程名稱: ");
        scanf(" %s",courses[i].name);
        printf("輸入課程代碼: ");
        scanf(" %d",&courses[i].code);
    }
    int input_amount,weekday,classNum,courseCode;
    printf("要輸入堂數: ");
    scanf("%d",&input_amount);
    for(int i=0;i<input_amount;i++){
        printf("輸入 星期幾 節次 課程代碼:  ");
        scanf(" %d %d %d",&weekday,&classNum,&courseCode);
        add_schedule(schedule,weekday,classNum,courseCode);
    }
    printf("\n");
    printf("\tMON.\tTUE.\tWED.\tTHU.\tFRI.\n");
    for(int i=0;i<CLASS;i++){
        printf("第%d堂\t",i+1);
        for(int j=0;j<WEEKDAY;j++){
            printf("%d\t",schedule[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n課程代碼對照\n\n");
    for(int i=0;i<COURSE_NUM;i++){
        printf("%d\t%s\n",courses[i].code,courses[i].name);
    }
    return 0;
}