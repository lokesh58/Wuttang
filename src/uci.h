#ifndef UCI_H
#define UCI_H

#include <string.h>

#include "position.h"
#include "search.h"

#define INPUTBUFFER 400 * 6

void parseGo(const char *line, searchInfo &info, Position &pos);
void parsePosition(const char *lineIn, Position &pos);
void UCI_loop(Position &pos, searchInfo &info);

#endif  // UCI_H
