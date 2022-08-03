// src/greeting.cpp
// #include "test_api.h"
char* helloUser( char* name ) {
  return name;
}
 
void helloUser2(void (*pf)(void))
{
  pf();
}