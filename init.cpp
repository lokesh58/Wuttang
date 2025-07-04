#include "init.h"

#include "bitboards.h"
#include "hashKey.h"
#include "movegen.h"
#include "polybook.h"

void initAll() {
  initHashKey();
  initMvvLva();
  initEvalMask();
  initPolyBook();
}
