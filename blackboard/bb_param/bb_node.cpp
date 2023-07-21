/**
 * bb_node.cpp
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#include "bb_node.h"
#include "core/error/error_macros.h"
#include "core/variant/variant.h"
#include "scene/main/node.h"

Variant BBNode::get_value(Object *p_agent, const Ref<Blackboard> &p_blackboard, const Variant &p_default) {
	ERR_FAIL_COND_V(p_agent == nullptr, Variant());
	ERR_FAIL_COND_V(!p_blackboard.is_valid(), Variant());

	Variant val;
	if (get_value_source() == SAVED_VALUE) {
		val = get_saved_value();
	} else {
		val = p_blackboard->get_var(get_variable(), p_default);
	}

	if (val.get_type() == Variant::NODE_PATH) {
		Node *agent = Object::cast_to<Node>(p_agent);
		ERR_FAIL_COND_V_MSG(agent == nullptr, Variant(), "BBNode: p_agent must be a Node.");
		return agent->get_node(val);
	} else {
		Node *node = Object::cast_to<Node>(val);
		if (unlikely(node == nullptr && val.get_type() != Variant::NIL)) {
			WARN_PRINT("BBNode: Unexpected variant type of a blackboard variable.");
			return p_default;
		} else {
			return node;
		}
	}
}
