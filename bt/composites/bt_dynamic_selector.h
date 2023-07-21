/**
 * bt_dynamic_selector.h
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#ifndef BT_DYNAMIC_SELECTOR_H
#define BT_DYNAMIC_SELECTOR_H

#include "bt_composite.h"

#include "core/object/object.h"

class BTDynamicSelector : public BTComposite {
	GDCLASS(BTDynamicSelector, BTComposite);

private:
	int last_running_idx = 0;

protected:
	virtual void _enter() override;
	virtual int _tick(double p_delta) override;
};

#endif // BT_DYNAMIC_SELECTOR_H