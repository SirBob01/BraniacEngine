#ifndef CHESS_BRAINIAC_H_
#define CHESS_BRAINIAC_H_

#include <vector>
#include <unordered_map>
#include <memory>
#include <thread>
#include <mutex>

#include "neural/brain.h"
#include "board.h"

namespace chess {
    class Brainiac {
        neural::NEATParameters _params;
        std::unique_ptr<neural::Brain> _brain;
        std::string _savefile;

        /**
         * Convert the board into a 66x1 row-vector
         * as input for the neural network.
         */
        std::vector<double> vectorize(Board &board);

        /**
         * Simulate a game between two phenomes
         */
        void simulate(neural::Phenome &a, neural::Phenome &b, std::mutex &mutex);

    public:
        Brainiac();

        /**
         * Generate the initial Brainiac instance and its networks
         */
        void generate();

        /**
         * Trains by playing games against itself and updating its neural network.
         * This network calculates the probability of winning at a particular board state.
         */
        void train();

        /**
         * Evaluates the board state and selects the best
         * possible move
         */
        Move evaluate(Board &board);

        /**
         * Load neural networks from disk
         */
        bool load();

        /**
         * Save neural networks to disk
         */
        void save();
    };
}

#endif