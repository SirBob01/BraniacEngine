#include <iostream>
#include <iomanip>
#include <chrono>
#include "engine/brainiac.h"
#include "engine/neural/phenome.h"
#include "engine/neural/brain.h"

uint64_t perft(chess::Board &b, int depth, int max_depth, bool verbose) {
    uint64_t nodes = 0;
    auto moves = b.get_moves();
    if(depth == 1) {
        return moves.size();
    }
    for(auto &move : moves) {
        b.execute_move(move);
        uint64_t children = perft(b, depth-1, max_depth, verbose);
        b.undo_move();
        if(depth == max_depth && verbose) {
            std::cout << move.standard_notation() << ": " << children << "\n";
        }
        nodes += children;
    }
    return nodes;
}

void perft_command() {
    int depth;
    std::cout << "Enter perft depth: ";
    std::cin >> depth;

    chess::Board b;
    b.print();
    std::cout << b.generate_fen() << "\n";

    for(int i = 1; i <= depth; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        std::cout << "Perft(" << i << ") = ";
        uint64_t nodes = perft(b, i, i, false);
        std::cout << nodes << " (";
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << duration.count()/1000000.0 << " s)\n";
    }
}

void debug_command() {
    int depth;
    // std::string fen_string;
    // std::cout << "Enter FEN string: ";
    // std::cin >> fen_string;
    std::cout << "Enter perft depth: ";
    std::cin >> depth;

    chess::Board b;
    b.print();
    std::cout << b.generate_fen() << "\n";

    std::string move_input;
    chess::Move move = {};
    while(depth) {
        uint64_t nodes = perft(b, depth, depth, true);
        if(depth == 1) {
            for(auto &m : b.get_moves()) {
                std::cout << m.standard_notation() << "\n";
            }
        }
        std::cout << "Evaluated " << nodes << " nodes\n";

        while(move.is_invalid()) {
            std::cout << "Enter move to visit subtree> ";
            std::cin >> move_input;
            std::string from = move_input.substr(0, 2);
            std::string to = move_input.substr(2, 2);
            char promotion = 0;
            if(move_input.length() == 5) {
                promotion = move_input[4];
            }
            move = b.create_move(chess::Square(from), chess::Square(to), promotion);
        }
        b.execute_move(move);
        b.print();
        std::cout << b.generate_fen() << "\n";
        move = {};
        depth--;
    }
}

void play_bot() {
    chess::Board b;
    chess::Brainiac bot;
    bool loaded = bot.load();

    chess::Move move;
    std::string move_input;
    chess::Color player_color;
    if(chess::neural::random() < 0.5) {
        player_color = chess::Color::White;
    }
    else {
        player_color = chess::Color::Black;
    }
    while(!b.is_checkmate() && !b.is_draw()) {
        b.print();
        std::cout << b.generate_fen() << "\n";
        if(b.is_check()) {
            std::cout << "Check!\n";
        }
        if(b.get_turn() != player_color) {
            b.execute_move(bot.evaluate(b));
        }
        else {
            while(move.is_invalid()) {
                std::cout << "Enter a move> ";
                std::cin >> move_input;
                if(move_input == "undo") {
                    if(!b.is_initial()) {
                        b.undo_move();
                        break;
                    }
                }
                else if(move_input == "redo") {
                    if(!b.is_latest()) {
                        b.redo_move();
                        break;
                    }
                }
                else if(move_input == "stop") {
                    return;
                }
                else {
                    std::string from = move_input.substr(0, 2);
                    std::string to = move_input.substr(2, 2);
                    char promotion = 0;
                    if(move_input.length() == 5) {
                        promotion = move_input[4];
                    }
                    move = b.create_move(chess::Square(from), chess::Square(to), promotion);
                }
            }
            if(!move.is_invalid()) {
                b.execute_move(move);
                move = {};
            }
        }
    }
    b.print();
    std::cout << b.generate_fen() << "\n";
    if(b.is_checkmate()) {
        std::cout << (b.get_turn() == chess::Color::White ? "Black" : "White") << " wins!\n";
    }
    else {
        std::cout << "Draw!\n";
    }
}

void play_command() {
    chess::Board b;
    chess::Move move;
    std::string move_input;
    while(!b.is_checkmate() && !b.is_draw()) {
        b.print();
        std::cout << b.generate_fen() << "\n";
        if(b.is_check()) {
            std::cout << "Check!\n";
        }
        while(move.is_invalid()) {
            std::cout << "Enter a move> ";
            std::cin >> move_input;
            if(move_input == "undo") {
                if(!b.is_initial()) {
                    b.undo_move();
                    break;
                }
            }
            else if(move_input == "redo") {
                if(!b.is_latest()) {
                    b.redo_move();
                    break;
                }
            }
            else if(move_input == "stop") {
                return;
            }
            else {
                std::string from = move_input.substr(0, 2);
                std::string to = move_input.substr(2, 2);
                char promotion = 0;
                if(move_input.length() == 5) {
                    promotion = move_input[4];
                }
                move = b.create_move(chess::Square(from), chess::Square(to), promotion);
            }
        }
        if(!move.is_invalid()) {
            b.execute_move(move);
            move = {};
        }
    }
    b.print();
    std::cout << b.generate_fen() << "\n";
    if(b.is_checkmate()) {
        std::cout << (b.get_turn() == chess::Color::White ? "Black" : "White") << " wins!\n";
    }
    else {
        std::cout << "Draw!\n";
    }
}

int main() {
    std::cout << "Chess Engine C++ v.1.0\n";
    chess::neural::randseed();
    std::string command;
    while(true) {
        std::cout << "Enter command> ";
        std::cin >> command;
        if(command == "perft") {
            perft_command();
        }
        else if(command == "debug") {
            debug_command();
        }
        else if(command == "play") {
            play_command();
        }
        else if(command == "bot") {
            play_bot();
        }
        else if(command == "quit") {
            break;
        }
    }
    return 0;
}