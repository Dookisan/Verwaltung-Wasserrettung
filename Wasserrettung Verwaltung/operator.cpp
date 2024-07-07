#include <iostream>
#include "utils.h"

std::ostream& operator<<(std::ostream& os, const work_state& ws) {
    switch (ws) {
    case work_state::special:
        os << "Special";
        break;
    case work_state::ek:
        os << "Ek";
        break;
    case work_state::used:
        os << "used";
        break;
    case work_state::free:
        os << "free";
        break;
    }
    return os;
}