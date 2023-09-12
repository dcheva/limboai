/**
 * test_call_method.h
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#ifndef TEST_CALL_METHOD_H
#define TEST_CALL_METHOD_H

#include "limbo_test.h"

#include "modules/limboai/blackboard/bb_param/bb_node.h"
#include "modules/limboai/blackboard/blackboard.h"
#include "modules/limboai/bt/tasks/bt_task.h"
#include "modules/limboai/bt/tasks/scene/bt_call_method.h"

#include "core/os/memory.h"

namespace TestCallMethod {

TEST_CASE("[Modules][LimboAI] BTCallMethod") {
	Ref<BTCallMethod> cm = memnew(BTCallMethod);

	SUBCASE("When node parameter is null") {
		cm->set_node_param(nullptr);
		cm->set_method("test");
		ERR_PRINT_OFF;
		CHECK(cm->execute(0.01666) == BTTask::FAILURE);
		ERR_PRINT_ON;
	}

	SUBCASE("With object on the blackboard") {
		Node *dummy = memnew(Node);
		Ref<Blackboard> bb = memnew(Blackboard);

		Ref<BBNode> node_param = memnew(BBNode);
		cm->set_node_param(node_param);
		Ref<CallbackCounter> callback_counter = memnew(CallbackCounter);
		bb->set_var("object", callback_counter);
		node_param->set_value_source(BBParam::BLACKBOARD_VAR);
		node_param->set_variable("object");
		cm->set_method("callback");

		cm->initialize(dummy, bb);

		SUBCASE("When method is empty") {
			cm->set_method("");
			ERR_PRINT_OFF;
			CHECK(cm->execute(0.01666) == BTTask::FAILURE);
			ERR_PRINT_ON;
		}
		SUBCASE("When method doesn't exist") {
			cm->set_method("not_found");
			ERR_PRINT_OFF;
			CHECK(cm->execute(0.01666) == BTTask::FAILURE);
			ERR_PRINT_ON;
		}
		SUBCASE("When method exists") {
			CHECK(cm->execute(0.01666) == BTTask::SUCCESS);
			CHECK(callback_counter->num_callbacks == 1);
		}

		memdelete(dummy);
	}
}

} //namespace TestCallMethod

#endif // TEST_CALL_METHOD_H
