/**
 * bt_condition.cpp
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#include "bt_condition.h"

String BTCondition::get_configuration_warning() const {
	String warning = BTTask::get_configuration_warning();
	if (!warning.is_empty()) {
		warning += "\n";
	}
	if (get_child_count() != 0) {
		warning += "Condition task can't have child tasks.\n";
	}
	return warning;
}