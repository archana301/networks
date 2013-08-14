#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main(){
 int s,a=1,n,r=1;
 char ms[1000];
 char mc [1000];
 struct sockaddr_in server , client;
 s = socket(AF_INET,SOCK_STREAM,0);
 if(s<0){
  printf("/nError in socket creation !!!");
 }
 else {
 printf(" \nSocket created successfully...");
 }
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
 server.sin_family = AF_INET;
 //server.sin_addr.s_addr = INADDR_ANY;
 server.sin_port = htons(3005);
 if(bind(s,(struct sockaddr *)&server,sizeof(server))<0){
  printf("\nBinding failed !!!");
 }
 else {
  printf("\nBinding successfull..."); 
 }
 listen(s,10);
 n = sizeof(client);
 a = accept(s,(struct sockaddr *)&client , (socklen_t *)&n);
 printf("\nConnection accepted..."); 
 while((r=recv(a,mc,sizeof(mc),0))>0){
  puts(mc);
  printf("\nSERVER : ");
  gets(ms);
  write(a,ms,sizeof(ms));
 }
 
 close(s);
return 0;
}
