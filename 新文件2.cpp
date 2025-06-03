#include <stdio.h>
#include <stdlib.h>
struct Student{
	int id;
	char name[20];
	int eng;
	int chi;
	struct Student *next;
};

int main(void){
	int choice;
	struct Student *list_head = NULL;
	while(1){
		printf("[1]新增 [2]修改 [3]刪除 [4]查詢\n");
		scanf(" %d",&choice);
		if(choice == 1){
			struct Student *new_student = (struct Student*)malloc(sizeof(struct Student));
			printf("ID: ");
			scanf(" %d",&new_student->id);
			printf("Name: ");
			scanf(" %s",new_student->name);
			printf("Eng: ");
			scanf(" %d",&new_student->eng);
			printf("Chi: ");
			scanf(" %d",&new_student->chi);
			new_student->next = list_head;
			list_head = new_student;
		}else if(choice == 2){
			int id;
			printf("修改的ID: ");
			scanf(" %d",&id);
			struct Student *cur = list_head;
			while(cur!=NULL){
				if(cur->id == id){
					printf("Eng: ");
					scanf(" %d",&cur->eng);
					printf("Chi: ");
					scanf(" %d",&cur->chi);
					break;
				}
				cur = cur->next;
			}
		}else if(choice == 3){
			int id;
			struct Student *cur = list_head;
			printf("刪除的ID: ");
			scanf(" %d",&id);
			if(cur->id == id){
				list_head = cur->next;
			}
			while(cur!=NULL){
				if(cur->next->id == id){
					cur->next = cur->next->next;
				}
				cur = cur->next;
			}
		}else if(choice == 4){
			int id;
			printf("查詢的ID: ");
			scanf(" %d",&id);
			struct Student *cur = list_head;
			while(cur!=NULL){
				if(cur->id == id){
					printf("ID: %d\n",cur->id);
					printf("Eng: %d\n",cur->eng);
					printf("Chi: %d\n",cur->chi);
					break;
				}
				cur = cur->next;
			}
			if (cur == NULL)printf("找不到");
		}
	}
	return 0;
}
