#pragma once

#include <vector>

#include "Position.hpp"

namespace Brainiac {
    /**
     * @brief Size of the transposition table.
     *
     */
    constexpr uint32_t TABLE_SIZE = 1 << 20;

    /**
     * @brief Mask to compute the table index.
     *
     */
    constexpr uint32_t TABLE_MASK = TABLE_SIZE - 1;

    /**
     * @brief Types of nodes depending on their value
     *
     */
    enum NodeType : uint8_t { Exact = 0, Lower = 1, Upper = 2 };

    /**
     * @brief Lower score bound.
     *
     */
    constexpr short LOWER_BOUND = -10000;

    /**
     * @brief Upper score bound.
     *
     */
    constexpr short UPPER_BOUND = -LOWER_BOUND;

    /**
     * @brief Transposition entry.
     *
     */
    struct TableEntry {
        NodeType type;
        short depth;
        short value = LOWER_BOUND;
    };

    /**
     * @brief Transposition table.
     *
     */
    class Transpositions {
        std::vector<TableEntry> _table;

      public:
        Transpositions();

        /**
         * @brief Read an entry from the table.
         *
         * @param pos
         * @return TableEntry
         */
        TableEntry get(Position &pos) const;

        /**
         * @brief Set an entry to the table.
         *
         * @param pos
         * @param entry
         */
        void set(Position &pos, TableEntry entry);
    };
} // namespace Brainiac