/**
 * bb_int_array.h
 * =============================================================================
 * Copyright 2021-2023 Serhii Snitsaruk
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 * =============================================================================
 */

#ifndef BB_INT_ARRAY_H
#define BB_INT_ARRAY_H

#include "bb_param.h"
#include "core/object/object.h"

class BBIntArray : public BBParam {
	GDCLASS(BBIntArray, BBParam);

protected:
	virtual Variant::Type get_type() const override { return Variant::PACKED_INT64_ARRAY; }
};

#endif // BB_INT_ARRAY_H