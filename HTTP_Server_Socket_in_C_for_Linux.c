#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
int main () {
 int server = 0 , client = 0 ; //defining server and client sockets descriptors   
  struct sockaddr_in serverAddr; //defining a struct to save server address value
 char message [9999];
  strcpy(message, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><H1>I Love socket programming in C++</H1></body></html>");
  server = socket(AF_INET, SOCK_STREAM, 0); // creating server socket with IP version 4, and it's type is Stream using TCP
serverAddr.sin_addr.s_addr = INADDR_ANY;
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(8080);
  bind(server, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  listen(server, 0);
  printf("Listening for incoming connections...\n");
  char buffer[1024];
  int msg_len;
  client = accept(server, (struct sockaddr*)NULL, NULL);
  printf("Client connected!");
  read(client, buffer, sizeof(buffer)-1);
  printf("Client says: buffer is %s \n", buffer);
  memset(buffer, 0, sizeof(buffer));
  msg_len = write(client, message, strlen(message));
  if(msg_len == 0) {
  printf("Client closed the connection\n");
  close(client);
    return -1;
  }
close(client);

return 0;}



