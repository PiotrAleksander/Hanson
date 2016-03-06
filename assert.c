#include "assert.h"

const Except_T Assert_Failed = { "Błąd asercji" };

void (assert)(int e) {
	assert(e);
}
