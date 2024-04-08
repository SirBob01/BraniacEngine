#pragma once

#include <array>

#include "Bitboard.hpp"
#include "Move.hpp"
#include "MoveList.hpp"
#include "Sliders.hpp"

namespace Brainiac {
    /**
     * @brief Table of king moves by bit index.
     *
     */
    constexpr std::array<Bitboard, 64> KING_MOVE_MASKS = {
        0x0000000000000302, 0x0000000000000705, 0x0000000000000e0a,
        0x0000000000001c14, 0x0000000000003828, 0x0000000000007050,
        0x000000000000e0a0, 0x000000000000c040, 0x0000000000030203,
        0x0000000000070507, 0x00000000000e0a0e, 0x00000000001c141c,
        0x0000000000382838, 0x0000000000705070, 0x0000000000e0a0e0,
        0x0000000000c040c0, 0x0000000003020300, 0x0000000007050700,
        0x000000000e0a0e00, 0x000000001c141c00, 0x0000000038283800,
        0x0000000070507000, 0x00000000e0a0e000, 0x00000000c040c000,
        0x0000000302030000, 0x0000000705070000, 0x0000000e0a0e0000,
        0x0000001c141c0000, 0x0000003828380000, 0x0000007050700000,
        0x000000e0a0e00000, 0x000000c040c00000, 0x0000030203000000,
        0x0000070507000000, 0x00000e0a0e000000, 0x00001c141c000000,
        0x0000382838000000, 0x0000705070000000, 0x0000e0a0e0000000,
        0x0000c040c0000000, 0x0003020300000000, 0x0007050700000000,
        0x000e0a0e00000000, 0x001c141c00000000, 0x0038283800000000,
        0x0070507000000000, 0x00e0a0e000000000, 0x00c040c000000000,
        0x0302030000000000, 0x0705070000000000, 0x0e0a0e0000000000,
        0x1c141c0000000000, 0x3828380000000000, 0x7050700000000000,
        0xe0a0e00000000000, 0xc040c00000000000, 0x0203000000000000,
        0x0507000000000000, 0x0a0e000000000000, 0x141c000000000000,
        0x2838000000000000, 0x5070000000000000, 0xa0e0000000000000,
        0x40c0000000000000,
    };

    /**
     * @brief Table of knight moves by bit index.
     *
     */
    constexpr std::array<Bitboard, 64> KNIGHT_MOVE_MASKS = {
        0x0000000000020400, 0x0000000000050800, 0x00000000000a1100,
        0x0000000000142200, 0x0000000000284400, 0x0000000000508800,
        0x0000000000a01000, 0x0000000000402000, 0x0000000002040004,
        0x0000000005080008, 0x000000000a110011, 0x0000000014220022,
        0x0000000028440044, 0x0000000050880088, 0x00000000a0100010,
        0x0000000040200020, 0x0000000204000402, 0x0000000508000805,
        0x0000000a1100110a, 0x0000001422002214, 0x0000002844004428,
        0x0000005088008850, 0x000000a0100010a0, 0x0000004020002040,
        0x0000020400040200, 0x0000050800080500, 0x00000a1100110a00,
        0x0000142200221400, 0x0000284400442800, 0x0000508800885000,
        0x0000a0100010a000, 0x0000402000204000, 0x0002040004020000,
        0x0005080008050000, 0x000a1100110a0000, 0x0014220022140000,
        0x0028440044280000, 0x0050880088500000, 0x00a0100010a00000,
        0x0040200020400000, 0x0204000402000000, 0x0508000805000000,
        0x0a1100110a000000, 0x1422002214000000, 0x2844004428000000,
        0x5088008850000000, 0xa0100010a0000000, 0x4020002040000000,
        0x0400040200000000, 0x0800080500000000, 0x1100110a00000000,
        0x2200221400000000, 0x4400442800000000, 0x8800885000000000,
        0x100010a000000000, 0x2000204000000000, 0x0004020000000000,
        0x0008050000000000, 0x00110a0000000000, 0x0022140000000000,
        0x0044280000000000, 0x0088500000000000, 0x0010a00000000000,
        0x0020400000000000,
    };

    /**
     * @brief Pawn advance masks. The first 64 entries are for white, remaining
     * 64 are for black.
     *
     */
    constexpr std::array<Bitboard, 128> PAWN_ADVANCE_MASKS = {
        0x100,
        0x200,
        0x400,
        0x800,
        0x1000,
        0x2000,
        0x4000,
        0x8000,
        0x10000,
        0x20000,
        0x40000,
        0x80000,
        0x100000,
        0x200000,
        0x400000,
        0x800000,
        0x1000000,
        0x2000000,
        0x4000000,
        0x8000000,
        0x10000000,
        0x20000000,
        0x40000000,
        0x80000000,
        0x100000000,
        0x200000000,
        0x400000000,
        0x800000000,
        0x1000000000,
        0x2000000000,
        0x4000000000,
        0x8000000000,
        0x10000000000,
        0x20000000000,
        0x40000000000,
        0x80000000000,
        0x100000000000,
        0x200000000000,
        0x400000000000,
        0x800000000000,
        0x1000000000000,
        0x2000000000000,
        0x4000000000000,
        0x8000000000000,
        0x10000000000000,
        0x20000000000000,
        0x40000000000000,
        0x80000000000000,
        0x100000000000000,
        0x200000000000000,
        0x400000000000000,
        0x800000000000000,
        0x1000000000000000,
        0x2000000000000000,
        0x4000000000000000,
        0x8000000000000000,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,

        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0x1,
        0x2,
        0x4,
        0x8,
        0x10,
        0x20,
        0x40,
        0x80,
        0x100,
        0x200,
        0x400,
        0x800,
        0x1000,
        0x2000,
        0x4000,
        0x8000,
        0x10000,
        0x20000,
        0x40000,
        0x80000,
        0x100000,
        0x200000,
        0x400000,
        0x800000,
        0x1000000,
        0x2000000,
        0x4000000,
        0x8000000,
        0x10000000,
        0x20000000,
        0x40000000,
        0x80000000,
        0x100000000,
        0x200000000,
        0x400000000,
        0x800000000,
        0x1000000000,
        0x2000000000,
        0x4000000000,
        0x8000000000,
        0x10000000000,
        0x20000000000,
        0x40000000000,
        0x80000000000,
        0x100000000000,
        0x200000000000,
        0x400000000000,
        0x800000000000,
        0x1000000000000,
        0x2000000000000,
        0x4000000000000,
        0x8000000000000,
        0x10000000000000,
        0x20000000000000,
        0x40000000000000,
        0x80000000000000,
    };

    /**
     * @brief Pawn capture masks. The first 64 entries are for white, remaining
     * 64 are for black.
     *
     */
    constexpr std::array<Bitboard, 128> PAWN_CAPTURE_MASKS = {
        0x200,
        0x500,
        0xa00,
        0x1400,
        0x2800,
        0x5000,
        0xa000,
        0x4000,
        0x20000,
        0x50000,
        0xa0000,
        0x140000,
        0x280000,
        0x500000,
        0xa00000,
        0x400000,
        0x2000000,
        0x5000000,
        0xa000000,
        0x14000000,
        0x28000000,
        0x50000000,
        0xa0000000,
        0x40000000,
        0x200000000,
        0x500000000,
        0xa00000000,
        0x1400000000,
        0x2800000000,
        0x5000000000,
        0xa000000000,
        0x4000000000,
        0x20000000000,
        0x50000000000,
        0xa0000000000,
        0x140000000000,
        0x280000000000,
        0x500000000000,
        0xa00000000000,
        0x400000000000,
        0x2000000000000,
        0x5000000000000,
        0xa000000000000,
        0x14000000000000,
        0x28000000000000,
        0x50000000000000,
        0xa0000000000000,
        0x40000000000000,
        0x200000000000000,
        0x500000000000000,
        0xa00000000000000,
        0x1400000000000000,
        0x2800000000000000,
        0x5000000000000000,
        0xa000000000000000,
        0x4000000000000000,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,

        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0x2,
        0x5,
        0xa,
        0x14,
        0x28,
        0x50,
        0xa0,
        0x40,
        0x200,
        0x500,
        0xa00,
        0x1400,
        0x2800,
        0x5000,
        0xa000,
        0x4000,
        0x20000,
        0x50000,
        0xa0000,
        0x140000,
        0x280000,
        0x500000,
        0xa00000,
        0x400000,
        0x2000000,
        0x5000000,
        0xa000000,
        0x14000000,
        0x28000000,
        0x50000000,
        0xa0000000,
        0x40000000,
        0x200000000,
        0x500000000,
        0xa00000000,
        0x1400000000,
        0x2800000000,
        0x5000000000,
        0xa000000000,
        0x4000000000,
        0x20000000000,
        0x50000000000,
        0xa0000000000,
        0x140000000000,
        0x280000000000,
        0x500000000000,
        0xa00000000000,
        0x400000000000,
        0x2000000000000,
        0x5000000000000,
        0xa000000000000,
        0x14000000000000,
        0x28000000000000,
        0x50000000000000,
        0xa0000000000000,
        0x40000000000000,
    };

    struct MoveGen {
        Bitboard friends;
        Bitboard enemies;
        Bitboard all;

        Bitboard f_king;
        Bitboard f_pawn;
        Bitboard f_rook;
        Bitboard f_knight;
        Bitboard f_bishop;
        Bitboard f_queen;

        Bitboard o_king;
        Bitboard o_pawn;
        Bitboard o_rook;
        Bitboard o_knight;
        Bitboard o_bishop;
        Bitboard o_queen;

        Bitboard ep;
        Color turn;

        Bitboard king_attacks(Square sq);

        Bitboard pawn_advances(Square sq);

        Bitboard pawn_doubles(Square sq);

        Bitboard pawn_captures(Square sq);

        Bitboard knight_attacks(Square sq);

        Bitboard rook_attacks(Square sq);

        Bitboard bishop_attacks(Square sq);

        Bitboard queen_attacks(Square sq);

        /**
         * @brief Generate moves onto a move list. Returns true if the friendly
         * king is in check.
         *
         * @param moves
         * @return true
         * @return false
         */
        bool generate(MoveList &moves);
    };
} // namespace Brainiac