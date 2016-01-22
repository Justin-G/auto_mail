#ifndef _AUTO_MAIL_H
#define _AUTO_MAIL_H
void get_time(char *);
void send_mail(char *);
void get_ip(char *);
void get_content(char *,char * ,char *);
void save_content(char *,char *);
int check_ip(char *,char *);
void read_ip(char *);
void clean_str(long int *);
#endif
