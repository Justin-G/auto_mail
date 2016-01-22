#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auto_mail.h"

int main(void){
	char out_ip[62]=""; 
	char last_ip[62]="";
	char content[100]="";
	char now_time[30]="";
	long int str_arr[4]={(long int)out_ip,(long int)last_ip,(long int)content,(long int)now_time};
	while(1){	
		get_ip(out_ip);
		//printf("%s %d\n",out_ip,strlen(out_ip));
		get_time(now_time);
		//printf("%s\n",now_time);
		get_content(content,now_time,out_ip);
		//printf("%s\n",content);
		read_ip(last_ip);
		save_content(content,now_time);
		if(!check_ip(out_ip,last_ip))
			sleep(180);
		else
			send_mail(now_time);
		clean_str(str_arr);
		sleep(3);
		
	}
	return 0;
}

