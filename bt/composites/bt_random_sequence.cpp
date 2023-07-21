/**
 * bt_random_sequence.cpp
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#include "bt_random_sequence.h"

void BTRandomSequence::_enter() {
	last_running_idx = 0;
	if (indicies.size() != get_child_count()) {
		indicies.resize(get_child_count());
		for (int i = 0; i < get_child_count(); i++) {
			indicies.set(i, i);
		}
	}
	indicies.shuffle();
}

int BTRandomSequence::_tick(double p_delta) {
	int status = SUCCESS;
	for (int i = last_running_idx; i < get_child_count(); i++) {
		status = get_child(indicies[i])->execute(p_delta);
		if (status != SUCCESS) {
			last_running_idx = i;
			break;
		}
	}
	return status;
}