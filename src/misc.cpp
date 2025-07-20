#include "misc.h"

#include <unistd.h>

#include <chrono>
#include <cstdio>
#include <cstring>

int getTimeMS() {
  auto now = std::chrono::steady_clock::now();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                now.time_since_epoch())
                .count();
  return static_cast<int>(ms);
}

#include <sys/select.h>

int InputWaiting() {
  struct timeval tv;
  fd_set readfds;

  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);

  return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) > 0;
}

void ReadInput(searchInfo &info) {
  int bytes;
  char input[256] = "", *endc;

  if (InputWaiting()) {
    info.stopped = true;
    do {
      bytes = read(STDIN_FILENO, input, 256);
    } while (bytes < 0);
    endc = strchr(input, '\n');
    if (endc) *endc = 0;

    if (strlen(input) > 0) {
      if (!strncmp(input, "quit", 4)) {
        info.quit = true;
      }
    }
    return;
  }
}
