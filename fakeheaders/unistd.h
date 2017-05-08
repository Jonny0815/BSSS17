#pragma once

// fake header for visual studio

int pipe(int pfd[2]) {return 0;}
int fork() {return 0;}
void close(int);
int read(int,const char*, int);
int write(int,const char*, int);
void sleep(int);