#pragma once

#include <iostream>

enum class work_state {
    special,
    ek,
    used,
    free,
};

std::ostream& operator<<(std::ostream& os, const work_state& ws);
    