/**
 * bt_composite.cpp
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#include "bt_composite.h"

String BTComposite::get_configuration_warning() const {
	String warning = BTTask::get_configuration_warning();
	if (!warning.is_empty()) {
		warning += "\n";
	}
	if (get_child_count() < 1) {
		warning += "Composite should have at least one child task.\n";
	}
	return warning;
}