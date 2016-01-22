#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auto_mail.h"
void get_ip(char * p_ip){
	char command[20]="curl ip.cn -m 30";
	int flag = 0;
	int cnum = 0;
	int the_ip;
	FILE * pipe;
	do{
		pipe = popen(command,"r");
		if(pipe == NULL){
			fprintf(stderr,"获取ip失败");
			exit(3);
		}
		fgets(p_ip,62,pipe);
		*(p_ip+62)='\0';
		if(*p_ip != '\0'){
			flag = 1;
		}
		
		if(sscanf(p_ip,"%*s %*c %*c %*c %*c %*c %d",&the_ip) == 0){
			flag = 0;
		}
		if(flag == 0)
			sleep(10);
	}while(!flag && cnum++ < 5);
	if(cnum == 6)
		system("shutdown");
	pclose(pipe);
	
}
void get_time(char * p_time){
	char command[20]="date \'+%F_%s\'";
	FILE * pipe = popen(command,"r");
	fgets(p_time,22,pipe);
	pclose(pipe);
}
void get_content(char * p_content,char * p_time,char * p_ip){
	strcat(p_content,p_time);
	strcat(p_content," ip =");
	strcat(p_content,p_ip);
	strcat(p_content,"\n");
	
}
void send_mail(char * p_time){
	char command[300]="mail -s \"";
	char user[20]="yourname@example.com";
	char file_path[35]="< /your/log/path";
	strcat(command,p_time);
	strcat(command,"\" ");
	strcat(command,user);
	strcat(command,file_path);
	system(command);
	//printf("%s\n",command);
}
void save_content(char * p_content,char * p_time){
	FILE * f_content;
	char file_name[70]="/your/log/path";
	f_content = fopen(file_name,"w");
	if(f_content == NULL){
		fprintf(stderr,"写入失败！");
		exit(1);
	}
	fprintf(f_content,"%s",p_content);
	fclose(f_content);
}
void read_ip(char * p_lip){
	FILE * p_log = fopen("/your/log/path","r");
	if(p_log == NULL){
		fprintf(stderr,"读取失败！");
		exit(2);
	}
	fseek(p_log,26L,SEEK_SET);
	fgets(p_lip,62,p_log);
	//printf("%s %d\n",p_lip,strlen(p_lip));
	fclose(p_log);
}
int check_ip(char * p_fip,char * p_lip){
	return strcmp(p_fip,p_lip);
}
void clean_str(long int * p_str_arr){
	int num = 0;
	char * p_str;
	for(;num < 4;num++){
		p_str = (char *)p_str_arr[num];
		p_str[0]='\0';
	}

}
