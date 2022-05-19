#ifndef BRAINIAC_TRANSPOSITIONS_H_
#define BRAINIAC_TRANSPOSITIONS_H_

#define TRANSPOSITION_TABLE_SIZE 0x1000000
#define TRANSPOSITION_HASH_MASK  0xFFFFFF

#include <vector>

#include "board.h"
#include "move.h"

namespace brainiac {
    /**
     * Types of nodes depending on their value
     */
    enum NodeType { Exact = 0, Lower = 1, Upper = 2 };

    /**
     * An entry in the table
     */
    struct TableEntry {
        uint64_t key;
        int depth;
        float value = -INFINITY;
        NodeType type;
        Move best_move;
    };

    /**
     * A hash table of visited nodes
     */
    class Transpositions {
        std::vector<TableEntry> _table;

      public:
        Transpositions() : _table(TRANSPOSITION_TABLE_SIZE){};

        /**
         * Set the entry of a board position
         *
         * If an entry already exists, only overwrite if the depth is higher
         */
        inline void set(Board &board, TableEntry &entry) {
            uint64_t index = board.get_hash() & TRANSPOSITION_HASH_MASK;
            TableEntry &curr = _table[index];
            if (curr.value == -INFINITY || entry.depth >= curr.depth) {
                _table[index] = entry;
            }
        }

        /**
         * Get the entry of a board position
         */
        inline TableEntry &get(Board &board) {
            return _table[board.get_hash() & TRANSPOSITION_HASH_MASK];
        }
    };
} // namespace brainiac

#endif