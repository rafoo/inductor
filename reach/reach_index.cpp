#include "reach_index.h"

#include <sstream>

using namespace std;
using namespace reach;

bool IndexReachability::add() {
    unsigned long size = map.size() + 1;
    vector<unsigned long> vec(size);

    for (size_t i = 0; i < size - 1; i++) {
        map[i].push_back(0);
        vec[i] = 0;
    }

    vec[size - 1] = 1;
    map.push_back(vec);

    return true;
}

bool IndexReachability::link(unsigned long x, unsigned long y) {
    if (x >= map.size() && y >= map.size())
        return false;

    map[x][y] = 1;
    close();

    return true;
}

bool IndexReachability::unlink(unsigned long x, unsigned long y) {
    if (x >= map.size() && y >= map.size())
        return false;

    map[x][y] = 0;

    return true;
}

bool IndexReachability::fill(unsigned long size) {
    if (size < map.size()) {
        return false;
    }

    size_t initSize = map.size();
    for (size_t i = initSize; i < size; i++) {
        add();
    }

    for (size_t i = 0, szi = map.size(); i < szi; i++) {
        for (size_t j = 0, szj = map[i].size(); j < szj; j++) {
            map[i][j] = 1;
        }
    }

    return true;
}

bool IndexReachability::find(unsigned long x, unsigned long y) {
    if (x >= map.size()) {
        return false;
    }

    return map[x][y] == 1;
}

std::vector<unsigned long> IndexReachability::find(unsigned long x) {
    if (x >= map.size()) {
        std::vector<unsigned long> empty;
        return empty;
    }

    return map[x];
}

void IndexReachability::close() {
    std::vector<std::vector<unsigned long>> copy;

    do {
        copy = copyMap();
        for (size_t i = 0, szi = map.size(); i < szi; i++) {
            for (size_t j = 0, szj = map[i].size(); j < szj; j++) {
                if (!map[i][j])
                    continue;

                for (size_t k = 0, szk = map[j].size(); k < szk; k++) {
                    if (map[j][k]) {
                        map[i][k] = 1;
                    }
                }
            }
        }

    } while (!equalsMap(copy));
}

IndexReachabilityPtr IndexReachability::clone() {
    IndexReachabilityPtr result = make_shared<IndexReachability>();
    result->map = map;
    return result;
}

bool IndexReachability::equals(const IndexReachabilityPtr& other) {
    return equalsMap(other->map);
}

bool IndexReachability::conj(const IndexReachabilityPtr& other) {
    if (map.size() != other->map.size())
        return false;

    // fixme Check if j does not need to be smaller than map[i].size()
    for (size_t i = 0, szi = map.size(); i < szi; i++) {
        for (size_t j = 0, szj = map.size(); j < szj; j++) {
            if (other->map[i][j] == 0)
                map[i][j] = 0;
        }
    }

    return true;
}

std::string IndexReachability::toString() {
    stringstream ss;
    ss << "{";

    bool first = true;
    for (unsigned long i = 0; i < map.size(); i++) {
        for (unsigned long j = 0; j < map[i].size(); j++) {
            if (!map[i][j])
                continue;

            if (!first) {
                ss << ", ";
            } else {
                first = false;
            }

            ss << "(" << i << ", " << j << ")";
        }
    }

    ss << "}";
    return ss.str();
}

std::vector<std::vector<unsigned long>> IndexReachability::copyMap() {
    std::vector<std::vector<unsigned long>> result;
    result.insert(result.begin(), map.begin(), map.end());
    return result;
}

bool IndexReachability::equalsMap(const std::vector<std::vector<unsigned long>>& other) {
    if (map.size() != other.size())
        return false;

    for (size_t i = 0, szi = map.size(); i < szi; i++) {
        if (map[i].size() != other.size())
            return false;

        for (size_t j = 0, szj = map[i].size(); j < szj; j++) {
            if (map[i][j] != other[i][j])
                return false;
        }
    }

    return true;
}