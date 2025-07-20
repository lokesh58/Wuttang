#include "init.h"

#include "bitboards.h"
#include "hashKey.h"
#include "movegen.h"

void initAll() {
  initHashKey();
  initMvvLva();
  initEvalMask();
}
