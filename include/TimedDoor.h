//  Copyright 2021 Krayushkina

#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_
#include <iostream>
#include <string>

class TimedDoor;

class TimerClient {
	@@ -23,28 +21,32 @@ class Door {
class DoorTimerAdapter : public TimerClient {
 private:
  TimedDoor& door;

 public:
  explicit DoorTimerAdapter(TimedDoor& doorIn) : door(doorIn) {}
  void Timeout() override;
};

class TimedDoor : public Door {
 private:
  DoorTimerAdapter* adapter;
  int iTimeout;
  bool opened;

 public:
  explicit TimedDoor(int time)
      : iTimeout(time), opened(false), adapter(new DoorTimerAdapter(*this)) {}
  bool isDoorOpened() override;
  void unlock() override;
  void lock() override;
  void DoorTimeOut();
  void throwState();
};

class Timer {
  TimerClient* client;
  void sleep(int);

 public:
  void tregister(int, TimerClient*);
};