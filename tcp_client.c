#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>
int main(){
 int s,c,p=1,r;
 char m[1000];
 char server_reply[2000];
 struct sockaddr_in client;
 s=socket(AF_INET,SOCK_STREAM,0);
 if(s<0){
   printf("\nSocket creation failed !!!");
 }
 printf("\nSocket created successfully...");
 client.sin_addr.s_addr = INADDR_ANY;
 client.sin_family = AF_INET;
 client.sin_port = htons(3005);
 c = connect(s,(struct sockaddr*)&client , sizeof(client));
 if(c<0){
  printf("\nThere was a connection error !!!");
  exit(1);
 }
 else{
  printf("\nConnection established successfully..."); 
 }
 while(p>0){
 printf("\nCLIENT : Enter the data : ");
 gets(m);
 p = send(s,m,1000,0);
 if(p<0){
  printf("Sending failed !!!");
 }
 //printf("The message has been sent successfully ...");
 r=recv(s,server_reply,sizeof(server_reply),0);
 printf("\n SERVER: ");
 puts(server_reply); 
}
return 0;
//shutdown(s,4);
close(s);
}

