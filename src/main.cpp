//  Copyright 2021 Krayushkina
#include "TimedDoor.h"
#include <iostream>
#include <string>

int main() {
  TimedDoor tDoor(5);
  tDoor.lock();
  tDoor.unlock();

  return 0;
}
